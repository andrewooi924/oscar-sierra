/* multithread_add.c */

#include <stdio.h>      
#include <pthread.h>    
#include <unistd.h>  
#include <stdlib.h>  
#include <ctype.h>

int sum = 0;
pthread_t tid;

//Prints out a "hello" message
void* print_hello(void* data) {

  int t = *(int *)data;
  
  //retrieve own thread ID
  tid = pthread_self();
  
  //increment the sum global variable by t
  sum += t;
  
  //print hello message and resulting value of sum
  printf("Hello from thread (%ld) - I was created in iteration %d. Current sum: %d\n", tid, t+1, sum);
  
}

//Main program
int main(int argc, char* argv[]) {

  //Check for only 1 integer argument (x)
  if (argc != 2) {
    printf("Please enter one digit!\n");
    exit(1);
  }

  //Check if argument is an integer
  int x = atoi(argv[1]);
  if (isdigit(x)) {
    printf("Please enter a digit!\n");
    exit(1);
  }
  
  //Array to store every created thread id
  pthread_t thread_id[x];
  
  //Loop that creates new threads
  for (int i = 0; i < x; i++) {
    pthread_create(&thread_id[i], NULL, print_hello, &i);
    printf("I am thread 1. Created new thread (%ld) in iteration %d. Current sum: %d\n", tid, i+1, sum);
    
    //Sleep for 1 second for every 4 created threads
    if ((i+1) % 4 == 0) {
      sleep(1);
    }
  }
  
  //Waiting for threads
  for (int i = 0; i < x; i++) {
    pthread_join(thread_id[i], NULL);
  }
  
  //Exit the program
  exit(0);
}
