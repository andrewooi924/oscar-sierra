/* reverse.c: reverses a given 4-digit number */

#include <stdio.h>

int main(void)
{
  int inp;
  int arr[4];

  printf("Enter 4-digit number: ");
  scanf("%d", &inp);

  arr[0] = inp % 10;
  inp = inp / 10;
  arr[1] = inp % 10;
  inp = inp / 10;
  arr[2] = inp % 10;
  inp = inp / 10;
  arr[3] = inp % 10;
  inp = inp / 10;

  printf("%d", arr[0]);
  printf("%d", arr[1]);
  printf("%d", arr[2]);
  printf("%d\n", arr[3]);

  return 0;
}