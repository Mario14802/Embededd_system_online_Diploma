#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letter;


printf("enter a character: ");
scanf("%c",&letter);

if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
{
    printf("%c is a vowel",letter);
}
else
{
    printf("%c is consonant",letter);
}

    return 0;
}
