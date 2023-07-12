#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(char arr[],int len);

int main()
{
    char arr[100];
    int i,n;
    printf("Enter the name: ");
    scanf("%s", arr);

    n=strlen(arr);

    fun(arr,n);


    return 0;
}

void fun(char arr[],int len)
{
    int i,c=0;
    char rev [100];
    for(i=len-1; i>=0; i--)
    {
        rev[c]=arr[i];
        c++;

    }
    rev[c]='\0';
    printf("the reversed array = %s",rev);
}
