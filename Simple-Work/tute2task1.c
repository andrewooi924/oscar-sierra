/* task1.c */
#include <stdio.h>

int main() {
  int x, y, z, res;
  
   printf("Please input the first positive integer: ");
   scanf("%d", &x);
  
   printf("Please input the second positive integer: ");
   scanf("%d", &y);
  
  if (x > y) 
  {
    z = x;
  }
  else 
  {
    z = y;
  }
  
  while (1) 
  {
    if ((z % x == 0) && (z % y == 0)) 
    {
      res = z;
      break;
    }
    z += 1;
  }
  
  printf("The lowest common multiple between %d and %d is %d\n", x, y, res);
  
  return 0;
}
