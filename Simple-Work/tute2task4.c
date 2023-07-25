/* task4.c */
#include <stdio.h>
#include <string.h>
#include "task4_unit_code.h"

int main() {
  int res;
  
  UnitCode x = {"FIT", 1047};
  UnitCode y = {"FIT", 1047};
  
  //Ternary operator that returns 1 if both members of the struct are equal, 0 otherwise
  res = ((strcmp(x.FacID, y.FacID) == 0) && (x.UnitID == y.UnitID)) ? 1 : 0;
  if (res == 1)
  {
    printf("Both UnitCode variables are identical.\n");
  }
  else
  {
    printf("The UnitCode variables are not equal to each other.\n");
  }
  
  return 0;
}
