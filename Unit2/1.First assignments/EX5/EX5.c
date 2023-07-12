/*
 ============================================================================
 Name        : EX5.c
 Author      : Mario
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char letter=0;
	printf ("enter a character:");
	fflush(stdin);fflush(stdout);
	scanf("%c",&letter);
	printf("ASCII value of %c =%d ",letter,letter);

}
