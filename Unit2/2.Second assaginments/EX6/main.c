#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,n=0;

    printf("enter the number\n");
    scanf("%d",&n);

    int sum=0;

    for(i=0;i<=n;i++)
    {
    sum = sum+i;
    }
    printf("the sum of natural numbers = %d",sum);

    return 0;
}
