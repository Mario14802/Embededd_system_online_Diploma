#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float a=0,b=0;

	printf("enter value of a:");
	scanf("%f",&a);


	printf("enter value of b:");
	scanf("%f",&b);

  a = a + b;
  b = a - b;
  a = a - b;


fflush(stdin);fflush(stdout);

	printf("After swapping, value of a = %.2f\n",a);

	printf("After swapping, value of b = %.2f",b);

	return (0);
}
