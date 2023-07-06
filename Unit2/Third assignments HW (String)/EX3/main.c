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


    n=strlen(a);
    char reversed [100];
    char c =0;
    for(i=n-1; i>=0; i--)
    {
        reversed[c]=a[i];
        c++;
    }
    reversed[c]='\0';
    printf("the reversed string = %s",reversed);
    return 0;
}
