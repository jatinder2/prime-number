
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define MIN_USER_INPUT 2
#define MAX_USER_INPUT 1000

void *getUserInput(){
    int *number_from_user=(int *)malloc(sizeof(int));

    puts("Enter a number to print all prime numbers in range [0 - number]");

    while(1){
        printf("Input : ");
        scanf("%d",number_from_user);

        if(*number_from_user<MIN_USER_INPUT || *number_from_user>MAX_USER_INPUT){
            printf("Please Enter a positive number from %d to %d\n",MIN_USER_INPUT,MAX_USER_INPUT);
            ///rewinds the input buffer (if user gives character type input it prevents infinite while loop
            rewind(stdin);
        }else break;
    }
    puts("Input thread received user input.");
    ///writing number_from_user to the second argument (a generic pointer) passed in thread join call
    pthread_exit(number_from_user);
}
