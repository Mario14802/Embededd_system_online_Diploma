#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=0;
    printf("enter the number: ");
    scanf("%d",&num);
    if(num%2==0)
    {
        printf("%d Is even",num);
    }

    else
    {
        printf("%d is odd",num);
    }



    return 0;
}
