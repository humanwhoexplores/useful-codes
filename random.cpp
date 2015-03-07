/* srand example */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



void shuffle(int array1[], int size)
{
     int i, temp, random, last;
 
     for (i = 0; i < size; i++)
           array1[i] = i + 1;
 
     for (last = size; last > 1; last--)
     {
           random = rand() % last;
           temp = array1[random];
           array1[random] = array1[last - 1];
           array1[last - 1] = temp;
     }
}

int main ()
{
/*  printf ("First number: %d\n", rand()%100);
  srand (time(NULL));
  printf ("Random number: %d\n", rand()%100);
  srand (1);
  printf ("Again the first number: %d\n", rand()%100);
*/
 
   int array[200],size;
   size =10;
   
   shuffle(array,size);
  for(int i=0;i<size;i++)
     printf("%d  ",array[i]);   
 
 
 
 
 
  return 0;
}


