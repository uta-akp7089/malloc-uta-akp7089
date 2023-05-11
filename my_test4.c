#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr1 = (char *) malloc(100);
    char *buf1 = (char *) malloc(1);
    char *ptr2 = (char *) malloc(512);
    char *buf2 = (char *) malloc(1);
    char *ptr3 = (char *) malloc(1000);
    char *buf3 = (char *) malloc(1);
    char * ptr4 = (char *) malloc(1000);
   
   
    free(ptr1);
    free(ptr3);
    free(ptr2);
    buf1 = buf1;
    buf2 = buf2;
    buf3 = buf3;
    ptr4 = ptr4;
    char *ptr5 = (char *) malloc(1000);
    ptr5 = ptr5;
  
    char *ptr6 = (char *) malloc(500);
    ptr6 = ptr6;

    free(ptr2);


}