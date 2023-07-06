#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int i,n;
    char a[100];
    char letter;
    int counter=0 ;


    // Scan matrix a
    printf("Enter the string: \n");
    scanf("%s", &a);
    printf("\n");

    fflush(stdout);
    fflush(stdin);

    printf("Enter the char you want to look for: \n");
    scanf("%c", &letter);
    printf("\n");

    n = sizeof(a) / sizeof(a[0]);  // n/strlen(a)


    for (i = 0; i < n; i++)
    {
        if(letter=a[i])
        {
            counter++;
        }

    }
    printf("the number of times this character is repeated is: %d",counter);
    return 0;
}
