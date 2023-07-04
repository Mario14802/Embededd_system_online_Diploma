#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char letter;
    printf("enter a character\n");
    scanf("%c",&letter);

    if(!(isdigit(letter)))
    {
        printf("%c is an alphabet",letter);
    }
else
    {
        printf("%c is not an alphabet",letter);
    }

    return 0;
}
