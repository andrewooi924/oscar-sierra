/* task2.c */
#include <stdio.h>

int main() {
  int n, temp;
  int i = 0;
  int sum = 0;
  
  printf("Please enter the number of elements: ");
  scanf("%d", &n);
  
  int array[n];
  
  while (i != n)
  {
    printf("Please enter the next number of the array: ");
    scanf("%d", &temp);
    array[i] = temp;
    i += 1;
  }
  
  for (i = 0; i < n; i++)
  {
    sum += array[i];
  }
  
  printf("The total sum is %d\n", sum);

  return 0;
}
