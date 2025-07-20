#include<stdio.h>
#include<stdbool.h>  

int 
main(int argc, char *agrv[]){
    int a , b;
    char op;
    /* ask user for input */
    printf("Enter the  calculation\n");
    /* read the input from the user */
    if(scanf("%d %c %d", &a, &op,&b)!= 3){ //fprintf  used to print formatted output to a specific output stream//
        fprintf(stderr, "Invalid input \n");// stderr is used to print the  error meassage seprately//
        return true; 
    }
    /* Perform operation based on the operator */

    switch(op){
        case '+':
        printf("%d\n", a + b);
        break;
        case '-':
        printf("%d\n", a - b);
        break;
        case '*':
        printf("%d\n", a * b);
        break;
        case'/':
        if(b != 0)
        printf("%d\n", a/b);
        else
        fprintf(stderr, "Division by zero\n");
        break;
        default:
        fprintf(stderr, "unknown operator\n"); 
    }
    return false;

}