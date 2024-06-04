#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int size = 100000000;
    int *numbers = (int *) malloc(sizeof(int) * size);
    int sum ;
    srand(0);
    int pipe1[2];
    pipe(pipe1);

    int ret = fork();

    if (ret == 0) {
        int csum = 0;
        for(int i=0; i < size/2; i++){
            numbers[i] = rand() % 3;
            csum += numbers[i];
        }
        write(pipe1[0], &csum, sizeof(csum));
        exit(0);
    }

    int psum = 0, csum;
    for(int i= size/2; i<size; i++){
        numbers[i] = rand() % 3;
        psum += numbers[i];
    }

    read(pipe1[1], &csum, sizeof(csum));

    sum = psum + csum;
    printf("The sum is: %d", sum);
    return 0;
}