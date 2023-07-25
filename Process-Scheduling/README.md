# User Manual for Scheduling Programs (task1.c, task2.c, task3.c)
Author: Ooi Yu Zhang

# Introduction
This user instruction manual will state the assumptions made about my interpretation of all the scheduling algorithm's implementation as well as show you how to use the program itself!

# Functionality
task1.c is a scheduling program that implements my interpretation of the First Come, First Served Scheduling Algorithm.
task2.c is a scheduling program that implements my interpretation of the Round Robin Scheduling Algorithm with a Time Quantum of 2. 
task3.c is a scheduling program that implements my interpretation of a Deadline-based Scheduling Algorithm.



# First Come, First Served Scheduling Algorithm
## How it works
1. The program has a 'time' variable which keeps track of the time elapsed in the program (in seconds). 
2. The program constantly checks the arrival times of every line in the file and adds them to a 'queue' if they have arrived. 
3. The program works on each process one by one from the top of the queue to the bottom of the queue which means it is on a first come, first served basis.
4. Every second, the program will process the currently running process as well as process all processes in ready state.
5. All processes that have finished executing are terminated immediately.
6. The program outputs a text file containing the wait time, turnaround time and whether each process met their deadlines. Each line is in the format '[Process Name] [Wait Time] [Turnaround Time] [Deadline Met]', not including the single quotes.

## Assumptions
1. The processes in proccesses.txt or any given file are listed in order of arrival time.
2. There are at most 100 processes in a file.
3. The name of each process is never more than 10 characters in length and does not contain spaces.
4. The given deadline for a process will always be greater or equal to the service time of that process.
5. Each line in the given file has to follow the format '[Process Name] [Arrival Time] [Service Time] [Deadline]', not including the single quotes.

## Compiling the program 'task1.c'
Run the command 'gcc -o task1 task1.c' in your terminal (without the single quotes!).
This outputs a single file that you will be using to run the program.

## How to use the program
1. Command: ./task1
This command will run the scheduling program on the provided sample process data file 'process.txt' and output a file called 'results-1.txt'. The output file contains information on the wait time and turnaround time of each process in the input file as well as whether each process met their deadlines.

2. Command: ./task1 <sourcefile>
This command will run the scheduling program on the user-specified process data file and output a file called 'results-1.txt'. The output file contains information on the wait time and turnarond time of each process in the given file as well as whether each process met their deadlines.



# Round Robin with Time Quantum 2 Scheduling Algorithm
## How it works
1. The program has a 'time' variable which keeps track of the time elapsed in the program (in seconds). 
2. The program constantly checks the arrival times of every line in the file and adds them to a 'queue' if they have arrived. 
3. The program works from the top of the queue to the bottom of the queue.
4. Every second, the program will process the currently running process as well as process all processes in ready state.
5. Every two seconds, the program checks whether two seconds has elapsed and switches the currently running process with the next ready process in the queue and moves the previously running process to the end of the queue.
6. All processes that have finished executing are terminated immediately.
7. The program outputs a text file containing the wait time, turnaround time and whether each process met their deadlines. Each line is in the format '[Process Name] [Wait Time] [Turnaround Time] [Deadline Met]', not including the single quotes.

## Assumptions
1. The processes in proccesses.txt or any given file are listed in order of arrival time.
2. There are at most 100 processes in a file.
3. The name of each process is never more than 10 characters in length and does not contain spaces.
4. The given deadline for a process will always be greater or equal to the service time of that process.
5. Each line in the given file has to follow the format '[Process Name] [Arrival Time] [Service Time] [Deadline]', not including the single quotes.
6. Newly arriving processes will get higher priority in the ready queue if a process gets preempted at the same time.

## Compiling the program 'task2.c'
Run the command 'gcc -o task2 task2.c' in your terminal (without the single quotes!).
This outputs a single file that you will be using to run the program.

## How to use the program
1. Command: ./task2
This command will run the scheduling program on the provided sample process data file 'process.txt' and output a file called 'results-2.txt'. The output file contains information on the wait time and turnaround time of each process in the input file as well as whether each process met their deadlines.

2. Command: ./task2 <sourcefile>
This command will run the scheduling program on the user-specified process data file and output a file called 'results-2.txt'. The output file contains information on the wait time and turnarond time of each process in the given file as well as whether each process met their deadlines.



# Deadline-based Scheduling Algorithm
## How it works
1. The program has a 'time' variable which keeps track of the time elapsed in the program (in seconds). 
2. The program constantly checks the arrival times of every line in the file and adds them to a 'queue' if they have arrived. 
3. The program works from the top of the queue to the bottom of the queue..
4. Every second, the program will process the currently running process as well as process all processes in ready state.
5. For every process added to the queue, the program will sort the whole process list in ascending order of deadlines so that the process in the list/queue with the closest deadline is at the top of the queue. 
6. If the process at the top of the queue is not the running process anymore, the program will find the running process and switch it to ready state.
7. All processes that have finished executing are terminated immediately.
8. The program outputs a text file containing the wait time, turnaround time and whether each process met their deadlines. Each line is in the format '[Process Name] [Wait Time] [Turnaround Time] [Deadline Met]', not including the single quotes.

## Why it works
Due to the assumption that the given deadline for a process will always be greater or equal to the service time of that process, this means that the algorithm prioritises processes with an overall shorter service time and deadline. The algorithm is then able to maximise the number of processes that meet their specified deadlines.

## Example scenario
For this example, I will be using the sample process data file 'process.txt' for ease of explanation. When running the scheduling programs task1 (FCFS) and task2 (RR=2) on it, each only have one process that meet its specified deadline. However, when using task3 (deadline-based), 3 out of 4 processes were able to meet their specified deadlines. This is due to the algorithm prioritising the processes with overall shorter service times and deadlines.

## Assumptions
1. The processes in proccesses.txt or any given file are listed in order of arrival time.
2. There are at most 100 processes in a file.
3. The name of each process is never more than 10 characters in length and does not contain spaces.
4. The given deadline for a process will always be greater or equal to the service time of that process.
5. Each line in the given file has to follow the format '[Process Name] [Arrival Time] [Service Time] [Deadline]', not including the single quotes.

## Compiling the program 'task3.c'
Run the command 'gcc -o task3 task3.c' in your terminal (without the single quotes!).
This outputs a single file that you will be using to run the program.

## How to use the program
1. Command: ./task3
This command will run the scheduling program on the provided sample process data file 'process.txt' and output a file called 'results-3.txt'. The output file contains information on the wait time and turnaround time of each process in the input file as well as whether each process met their deadlines.

2. Command: ./task3 <sourcefile>
This command will run the scheduling program on the user-specified process data file and output a file called 'results-3.txt'. The output file contains information on the wait time and turnarond time of each process in the given file as well as whether each process met their deadlines.
