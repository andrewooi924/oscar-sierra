/**
 * task1.c : A First-Come-First-Served Scheduling Program. The program utilises a queue to schedule processes and works on
 * processes one by one from the top of the queue to the bottom of the queue. The program optionally accepts a process data
 * file as input.
 * Name: Ooi Yu Zhang
 * Student ID: 32713339
 * Start Date: 27/9/2022
 * Last Modified: 1/10/2022
 */
 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

/* Special enumerated data type for process state */
typedef enum {
  READY, RUNNING, EXIT
} process_state_t;

/* C data structure used as process control block. The scheduler
 * should create one instance per running process in the system.
 */
typedef struct {
  char process_name[11]; // A string that identifies the process
  
  /* Times are measured in seconds. */
  int entryTime; // The time process entered system
  int serviceTime; // The total CPU time required by the process
  int remainingTime; // Remaining service time until completion
  int deadline; // Deadline for the process to complete
  int waitTime; // The time the process has waited in READY state
  int turnaroundTime; // The turnaround time of the process
  int deadlineMet; // Integer indicating whether the process met the deadline, 0 if FALSE, 1 if TRUE
  
  process_state_t state; // Current process state (e.g. READY)
} pcb_t;

/**
 * Function that calculates the total amount of service time
 * *fp : The input file
 * Returns the total amount of service time
 */
int countService(FILE *fp) {
  int sumTime, serviceTime;
  
  //Calculating the total service time
  while (fscanf(fp, "%*s %*d %d %*d\n", &serviceTime) != EOF) {
    sumTime += serviceTime;
  }
  
  //Reset file pointer to start of file
  rewind(fp);
  
  return sumTime;
}

/**
 * Function that processes all ready processes
 * processes[]: The process queue/process list containing all ready and running processes
 * counter: The number of process control blocks in the list
 * time: The current elapsed time in the program (in seconds)
 */
void processReady(pcb_t processes[], int counter, int time) {
  //Check if process at top of queue is READY
  if (processes[0].state == READY) {
    //Switch to RUNNING
    processes[0].state = RUNNING;
    //Print running message
    printf("Time %d: %s is in the running state.\n", time, processes[0].process_name);
  }
    
  //Increment wait time for all processes in READY state
  for (int i = 1; i < counter; i++) {
    processes[i].waitTime += 1;
  }
}

/**
 * Function that processes the running process
 * processes[]: The process queue/process list containing all ready and running processes
 * Returns nothing as it modifies the process queue/list
 */
void processRunning(pcb_t processes[]) {
  //Check if process at top of queue is RUNNING
  if (processes[0].state == RUNNING) {
    //Decrement remaining time for all processes in queue
    processes[0].remainingTime -= 1;
  }

  //Check if process at top of queue has finished running
  if (processes[0].remainingTime == 0 ) {
    processes[0].state = EXIT;
  }
}

/**
 * Function that calculates the result of the scheduling program and writes it to the output file
 * processes[]: The process queue/process list containing all ready and running processes
 * counter: The number of process control blocks in the list
 * *output: The output file to write to
 */
void calculateResult(pcb_t processes[], int counter, FILE *output) {
  //Calculate turnaround time for the process
   processes[0].turnaroundTime = processes[0].serviceTime + processes[0].waitTime;
     
  // Check if process met the deadline
  if (processes[0].turnaroundTime <= processes[0].deadline) {
    processes[0].deadlineMet = 1;
  }
  else {
    processes[0].deadlineMet = 0;
  }
      
  //Write to output file
  fprintf(output, "%s %d %d %d\n", processes[0].process_name, processes[0].waitTime, processes[0].turnaroundTime, processes[0].deadlineMet);
      
  //Remove terminated process at top of queue from array and push all processes
  for (int i = 0; i < counter; i++) {
    processes[i] = processes[i+1];
  }
}

int main(int argc, char *argv[]) {

  //Instance variables
  FILE *fp; // Input file
  FILE *output; // Output file
  pcb_t processList[101]; //Array of process control blocks
  char processName[11]; //Stores the name of the current process
  long int processFP; //Stores the current position of file pointer for tracking next arrival
  int arrivalTime, serviceTime, deadline;
  int counter = 0; // Pointer for processList
  int time = 0; // Time throughout the program (in seconds)
  int sumTime; // The total amount of service time
  
  //Open process file
  //Check if a filepath argument is given in command line
  if (argc > 1 && isalnum(*argv[1]) != 0) {
    fp = fopen(argv[1], "r");
  }
  else {
    fp = fopen("process.txt", "r");
  }
  
  //Check if file exists
  if (fp == NULL) {
    printf("File does not exist!\n");
    return 1;
  }
  
  //Open output file, creates one if it doesn't exist
  output = fopen("results-1.txt", "a");
  if (output == NULL) {
    printf("File does not exist!\n");
    return 1;
  }
  
  //Calculate the total amount of service time
  sumTime = countService(fp);
  
  //Start pulling processes from file line by line
  while (time <= sumTime) {
  
    //Assume processes in file are sorted in ascending order in terms of arrival time
    //Read formatted input from file
    while (fscanf(fp, "%s %d %d %d\n", processName, &arrivalTime, &serviceTime, &deadline) != EOF) {
      //Check if process has arrived
      if (time == arrivalTime) {
        //Initialise all values in process control block
        strcpy(processList[counter].process_name, processName);
        processList[counter].entryTime = time;
        processList[counter].serviceTime = serviceTime;
        processList[counter].remainingTime = serviceTime;
        processList[counter].deadline = deadline;
        processList[counter].waitTime = 0;
        processList[counter].state = READY;
      
        //Print arrive message
        printf("Time %d: %s has entered the system.\n", time, processList[counter].process_name);
      
        //Increment counter
        counter++;
      }
    }
    
    //Check if time is equal to the arrival time of the process at the top of the queue
    if (time != arrivalTime) {
      //Move pointer to the next process that is going to arrive next
      fseek(fp, processFP, SEEK_SET);
    }
    
    //Store pointer to next process that is going to arrive next
    processFP = ftell(fp);
    
    //Process the running process
    processRunning(processList);

    //Check if process at top of queue is EXIT
    if (processList[0].state == EXIT) {
      //Print exit message
      printf("Time %d: %s has finished execution.\n", time, processList[0].process_name);
      
      //Calculate and write results to output file
      calculateResult(processList, counter, output);
      
      //Decrement counter after removing an element from the list
      counter--;
    }
    
    //Check if queue is empty and time is equal to the total service time
    if (counter == 0 && time == sumTime) {
      break;
    }
    
    //Process all processes in READY state
    processReady(processList, counter, time);
    
    //Increment time by 1 second
    time++;
  }
  
  //Close both files before exiting
  fclose(fp);
  fclose(output);
  
  //Exit program
  return 0;
}

