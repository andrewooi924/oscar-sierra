/* random.c: generates a random sequence of six numbers */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int res;

  //Seed using time (in seconds)
  srand(time(NULL));

  //Set upper limit to 999999 and lower limit to 100000
  res = (rand() % (999999 - 100000 + 1) + 100000);

  //Output
  printf("%d\n", res);

  return 0;
}
