/* task3.c */
#include <stdio.h>

int find_largest(int the_array[], int num_elements){
  int i;
  int max = 0;
  int *xptr;
  
  for (i = 0; i < num_elements; i++)
  {
    if (the_array[i] > max)
    {
      max = the_array[i];
      xptr = &the_array[i];
    }
  }
  
  return *xptr;
}

int main() {
  int array[5] = {100, 230, 10, 89, 8932};
  int n = 5;
 
  printf("The largest element in the array is %d\n", find_largest(array, n));
  
  return 0;
}
