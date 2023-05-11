#include <stdio.h>
#include <stdlib.h>

int main()
{
    //testing best fit

    char *ptr1 = (char *) malloc(1000);
    char *buf1 = (char *) malloc(1);
    char *ptr2 = (char *) malloc(5000);
    char *buf2 = (char *) malloc(10);
    char *ptr3 = (char *) malloc(8000);
    printf("Best fit should pick this address: %p\n",ptr2);
    
    buf1 = buf1;
    buf2 = buf2;


    free(ptr1);
    free(ptr2);
    free(ptr3);
    
    char *ptr4 = (char *) malloc(4000);
    printf("Chosen address: %p\n",ptr4);


    free(ptr4);

}