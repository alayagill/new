#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[1000];
int s = 100;
void * add (void *num)
{
  int sum = 0;
  int number = (int) num;
  int size = s + number;
  int loop=size-s;
  int i;
  for ( i = loop; i < size; i++)
	sum = sum + arr[i];
  return ((void *) sum);
}

int main ()
{
  int i;
  for ( i = 0; i < 1000; i++)
    arr[i] = i + 1;
  int status[10];
  pthread_t array[10];
  for (i = 0; i < 10; i++)
    pthread_create (&array[i], NULL, add, (void *) (i * s));
  for (i = 0; i < 10; i++)
    pthread_join (array[i], (void **) &status[i]);
  int sum = 0;
  for (i = 0; i < 10; i++)
    sum = sum + status[i];
  printf ("%d ", sum);
  return 0;
}
