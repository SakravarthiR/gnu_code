#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]){
    int number,guess;
    srand((unsigned int) time(NULL));
    number = rand()% 10 + 1;
    printf("Guess the number betwenn 1 and 10:");

    if(scanf("%d", &guess)==1){
        if(guess ==  number)
        printf("Correct:\n");
        else
        printf("Wrong, it was %d\n", number);
    }  else{
        fprintf(stderr, "invalid input\n");
    }
    return 0;
}