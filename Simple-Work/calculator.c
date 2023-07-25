/* calculator.c: performs basic arithmetic operations */

#include <stdio.h>

int add(int x, int y)
{
  return x + y;
}

int subtract(int x, int y)
{
  return x - y;
}

int multiply(int x, int y)
{
  return x * y;
}

int divide(int x, int y)
{
  return x / y;
}

int main(void)
{
  int x, y, res;

  printf("Enter first number: ");
  scanf("%d", &x);
  
  printf("Enter second number: ");
  scanf("%d", &y);

  res = add(x,y);
  printf("%d\n", res);

  res = subtract(x,y);
  printf("%d\n", res);

  res = multiply(x,y);
  printf("%d\n", res);

  res = divide(x,y);
  printf("%d\n", res);

  return 0;
}