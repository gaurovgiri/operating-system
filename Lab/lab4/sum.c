#include <stdio.h>
#include <stdlib.h>

int main(){
    int size = 100000000;
    int *numbers = (int *) malloc(sizeof(int) * size);
    int sum = 0;
    srand(0);

    for(int i=0; i < size; i++){
        numbers[i] = rand() % 3;
        sum += numbers[i];
    }

    printf("The sum is: %d\n", sum);
    return 0;
}