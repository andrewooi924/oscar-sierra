/* initials.c: displays the initials of the user */

#include <stdio.h>
#include <string.h>

int main(void)
{
  char firstName[20], lastName[20], fnInitial, lnInitial;

  printf("Enter first name: ");
  scanf("%s", firstName);

  printf("Enter last name: ");
  scanf("%s", lastName);

  fnInitial = firstName[0];
  lnInitial = lastName[0];

  printf("%c.", fnInitial);
  printf("%c.\n", lnInitial);

  return 0;
}