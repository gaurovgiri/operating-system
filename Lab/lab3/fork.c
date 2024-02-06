#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    int ret;
    // pid_t pid = getpid();
    // printf("pid: %d\n",pid); runs once before forking

    pid_t pid;
    int numb = 3;
    ret = fork();
    
    if (ret == 0){
        pid = getpid();
        numb = 4;
        // sleep(1);
        printf("numb = %d ",numb);
        printf("Child pid: %d\n",pid);
        exit(0);
    }
    wait(NULL);
    pid = getpid();
    printf("numb = %d ",numb);
    printf("Parent pid: %d\n",pid);

    // printf("hi\n");
    // printf("ret = %d\n", ret);

    return 0;
}