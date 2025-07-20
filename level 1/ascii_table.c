#include<stdio.h>
int
main (int argc , char *argv[]){
    /* Loop through acii values from 0 to 127 */
    for(int i =0; i<128; i++){
        /* print ASCII number and character */
        printf("%3d = '%c'\n", i , (i>=32 && i<= 126) ? i: '-');
    }
    return 0;
}