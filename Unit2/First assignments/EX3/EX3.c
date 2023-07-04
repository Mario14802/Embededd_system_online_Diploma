/*
 ============================================================================
 Name        : EX3.c
 Author      : Mario
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num1,num2=0;
	printf("Enter two numbers: ");
	fflush(stdin),fflush(stdout);
	scanf("%d",&num1);
	scanf("%d",&num2);
	int sum = num1+num2;
	printf("sum=%d",sum);

	return(0);
}
