/* sphere.c: computes the surface area and volume of a sphere */

#include <stdio.h>

int main(void){
  float radius, area, volume;
  float PI = 3.14;
    
  printf("Enter the radius of the sphere: ");
  scanf("%f", &radius);
    
  area = 4 * PI * radius * radius;
  volume = 4 / 3 * PI * radius * radius * radius;
    
  printf("Surface Area of Sphere =  %.2f \n", area);
  printf("Volume of Sphere = %.2f \n", volume);
  return 0;
}