#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *ptr1 = (char *)malloc(1000);
    ptr1 = ptr1;
    char *ptr_array[1024];
    int i;
    for (i = 0; i < 1024; i++)
    {
        ptr_array[i] = (char *)malloc(1024);

        ptr_array[i] = ptr_array[i];
    }
    char *ptr2 = (char *) malloc(512);
    char *buf = (char *) malloc(1);
    buf = buf;
    ptr2 = ptr2;
    char *ptr3 = (char *) malloc(1000);

    free(ptr2);
    char *ptr6 =(char *) malloc(500);
    free(ptr3);

    char *ptr7 =(char *) malloc(900);
    ptr7 = ptr7;
    for (i = 0; i < 1024; i++)
    {
        free(ptr_array[i]);
    }
    free(ptr6);
}