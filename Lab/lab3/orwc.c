#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
    // int fd = open("file1.txt",O_WRONLY);
    // write(fd, "hello world\n", 12);
    // close(fd);

    // int fd = open("file1.txt",O_RDONLY);
    // char message[20];
    // read(0,message,10);
    // message[5] = '\0';
    // printf("The content is: %s",message);
    // close(fd); 

    char keyboard_inp[20];
    read(0,keyboard_inp,10);
    keyboard_inp[10] = '\0';
    printf("The content is: %s\n",keyboard_inp);

    return 0;
}