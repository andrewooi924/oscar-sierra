/* socket_client.c */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SOCKETNAME "mynewsocket"

int main(int argc, char *argv[])
{
  char buffer[1024];
  int n, sock, len;
  struct sockaddr_un name;

  /******************************************************************************
  * YOUR TASK:                                                                  *
  * Create a new socket.                                                        *
  ******************************************************************************/

  // Create a new socket
  sock = socket(AF_UNIX, SOCK_STREAM, 0);

  // Create the address of the server.
  memset(&name, 0, sizeof(struct sockaddr_un));
  name.sun_family = AF_UNIX;
  strcpy(name.sun_path, SOCKETNAME);
  len = sizeof(name.sun_family) + strlen(name.sun_path);

  // Connect to the server.
  if (connect(sock, (struct sockaddr *)&name, SUN_LEN(&name)) < 0)
  {
    perror("client: connect");
    exit(1);
  }

  /******************************************************************************
  * YOUR TASK:                                                                  *
  * Continuously read data from standard input and send the data to the socket. *
  ******************************************************************************/

  printf("Writing to server:\n");

  while(fgets(buffer, 1024, stdin) != NULL) 
  {
    send(sock, buffer, 1024, 0);
  }

  printf("Finished writing\n");

  close(sock);
  exit(0);
}
