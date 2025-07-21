#include<stdio.h> // for input and output function
#include<string.h>// for string length
#include<ctype.h>//For character string checker
#include<stdbool.h>


int 
is_strong_password(const char *password){ //const is used to not to modify the string inside the function
    int has_upper =0;
    int has_lower =0;
    int has_digit =0;
    int has_special =0;

 //loop through the password if the password is not empty
    for(int i =0; password[i] != '\0'; i++){
        if(isupper(password[i]))
        has_upper = true;

        if(islower(password[i]))
        has_lower = true;

        if(isdigit(password[i]))
        has_digit = true;
    
        if(!isalnum(password[i]))
        has_special=true;
    }
    return strlen(password) >= 8 && has_upper && has_lower && has_digit && has_special;
}

int
main(void)
{
 char password[50];
 printf("Enter password: ");
 scanf("%99s", password);// it is used deny the space from the user input

 if(is_strong_password(password))

   printf("The password is strong! \n");
   else
   printf("Weak password! Must be 8+ char with upper/lower/digit/symbol.\n");
return 0 ;
}