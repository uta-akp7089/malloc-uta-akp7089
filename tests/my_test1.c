#include <stdlib.h>
#include <stdio.h>

int main()
{
  printf("Running my test 1 to test first fit.\n");

  char * ptr = ( char * ) malloc ( 1000 );
  char * buf = (char *) malloc ( 1 );
  char * ptr3 = (char *) malloc ( 6000 );
  free( ptr ); 
  free( ptr3 );
  buf = buf;
  char * ptr4 = malloc( 5000 );
  free( ptr4 );

  return 0;
}
