#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num=0;
    printf("enter a number\n");
    scanf("%f",&num);

    if(num<0)
    {
        printf("this number is negative :%.2f",num);
    }
    else if(num>0)
    {
        printf("this number is positive :%.2f",num);
    }
    else
     printf("this number is :%.2f",num);



    return 0;
}
