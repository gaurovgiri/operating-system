#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void hello(){
    return;
}

int main(){
    pid_t pid = getpid();
    printf("The pid of this process is: %d\n", pid);
    pid_t ppid = getppid();
    printf("The parent's pid of this process is: %d\n", ppid);
    return 0;
}

