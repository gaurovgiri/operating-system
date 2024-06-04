#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define BUFSIZE 15

sem_t empty;
sem_t full;

int buffer[BUFSIZE];
int in=0, out=0;

pthread_mutex_t mutex;

#define NUMBER_OF_CONSUMERS 1
#define NUMBER_OF_PRODUCERS 10

void *producer(int *producer_number){
    int item;
    srand(21);
    while(1){
        sleep(rand()%3);
        item = rand()%100;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] =item;
        printf("The item %02d is inserted by producer(%d) at position %d \n", item, *producer_number, in);
        in = (in +1) % BUFSIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(int *consumer_number){
    srand(22);
        while(1){
        sleep(rand()%3);
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("The item %02d is consumed by consumer(%d) from position %d \n", item, *consumer_number, out);
        out = (out + 1) % BUFSIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main(){
    pthread_t producerThread[NUMBER_OF_PRODUCERS], consumerThread[NUMBER_OF_CONSUMERS];
    int i;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFSIZE);
    sem_init(&full, 0, 0);
    
    int producerNumber[NUMBER_OF_PRODUCERS];
    for( i=0; i<NUMBER_OF_PRODUCERS;i++){
        producerNumber[i] = i; 
    }
    
    int consumerNumber[NUMBER_OF_CONSUMERS];
    for( i=0; i<NUMBER_OF_CONSUMERS;i++){
        consumerNumber[i] = i; 
    }


    for( i=0; i<NUMBER_OF_CONSUMERS; i++){
        pthread_create(&consumerThread[i],NULL, (void *)consumer, &consumerNumber[i]);
    }

    for(int i=0; i<NUMBER_OF_PRODUCERS; i++){
        pthread_create(&producerThread[i],NULL, (void *)producer, &producerNumber[i]);
    }

    sleep(1);
    printf("waiting for thread to complete\n");

    for ( i=0;i < NUMBER_OF_CONSUMERS; i++){
        pthread_join(consumerThread[i], NULL);
    }
    for ( i=0;i < NUMBER_OF_PRODUCERS; i++){
        pthread_join(producerThread[i], NULL);
    }

    return 0;
}