#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   long t=0;
   printf("In main: creating thread %ld\n", t);
   pthread_create(&threads[t], NULL, PrintHello, (void *)t);
   t++;
   
   printf("In main: creating thread %ld\n", t);
   pthread_create(&threads[t], NULL, PrintHello, (void *)t);
   t++;

   /* Last thing that main() should do */
   pthread_exit(NULL);
}

