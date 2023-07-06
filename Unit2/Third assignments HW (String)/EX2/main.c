#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100];
    char len;


    // Scan matrix a
    printf("Enter the string: \n");
    scanf("%s", &a);
    printf("\n");

    len = 0;
    while (a[len] != '\0')
    {
        len++;
    }

    printf("The length of the string is: %d\n", len);
    return 0;
}

