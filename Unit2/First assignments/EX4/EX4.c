/*
 ============================================================================
 Name        : EX4.c
 Author      : Mario
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float num1,num2=0;
		printf("enter two numbers");
		fflush(stdin); fflush(stdout);
		scanf("%f",&num1);
		scanf("%f",&num2);
		float product =num1*num2;
		printf("Product: %f",product);


		return (0);
}
