/* msq_client.c */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSQKEY 348581
#define MSQSIZE 32

struct msgbuf
{
  long mtype;
  char mtext[MSQSIZE];
};

int main(int argc, char *argv[])
{
  key_t key;
  int n, msqid, len;
  struct msgbuf mbuf;

  // Get a message queue. The server must have created it.
  key = MSQKEY;
  if ((msqid = msgget(key, 0666)) < 0)
  {
    perror("client: msgget");
    exit(1);
  }
  
  printf("Writing to server:\n");

  /**************************************************************************************
  * YOUR TASK:                                                                          *
  * Continuously read data from standard input and send the data as messages of type 1. *
  ***************************************************************************************/

  while(fgets(mbuf.mtext, sizeof(mbuf.mtext), stdin) != NULL) 
  {
    mbuf.mtype = 1;
    
    if (msgsnd(msqid, &mbuf, sizeof(mbuf.mtext), 0) == -1)
    {
      perror ("client: msgsnd");
      exit(1);
    }
  
  
  /**************************************************************************************
  * YOUR TASK:                                                                          *
  * When an empty message is read, send a message of type 2 to indicate no more data.   *
  ***************************************************************************************/
  }
  
  //No more messages, set message type to "Type 2"
  mbuf.mtype = 2;
  
  if (msgsnd(msqid, &mbuf, sizeof(mbuf.mtext), 0) < 0)
  {
    perror("client: msgsnd");
    exit(1);
  }
  
  printf("Finished writing\n");
  
  exit(0);
}
