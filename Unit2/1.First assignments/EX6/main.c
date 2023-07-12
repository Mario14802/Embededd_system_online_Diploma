
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float a=0,b=0;

	printf("enter value of a:");
	scanf("%f",&a);


	printf("enter value of b:");
	scanf("%f",&b);

	float x=0;
	x=a;
	a=b;
	b=x;
fflush(stdin);fflush(stdout);

	printf("After swapping, value of a = %.21.f\n",a);

	printf("After swapping, value of b = %.2f",b);

	return (0);
}
