#include <stdio.h>
#include <stdlib.h>
#define NULL ((void*)0)

int main() {
    char str[100];
    char *ptr=NULL;

    printf("Input a string : ");
    scanf("%s", str);

    ptr = str + strlen(str) - 1; // point to the last character

    printf("Reverse of the string is : ");

    while (ptr >= str) {
        printf("%c", *ptr);
        ptr--;
    }

    return 0;
}




