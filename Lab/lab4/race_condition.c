#include <pthread/pthread.h>
#include <stdio.h>

void sayHello(){
    printf("hello\n");
}

int main(){
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, (void *)&sayHello, NULL);
    
    pthread_create(&thread2, NULL, (void *)&sayHello, NULL);

    printf("hi\n");

    printf("hey\n");


    pthread_join(thread1, NULL);

   
    pthread_join(thread2, NULL);


    return 0;
}