#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1=0,num2=0,num3=0;

    printf("Enter three numbers: \n");
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    printf("Enter the third number: ");
    scanf("%f", &num3);

    if(num1>num2)
    {
        if(num1>num3)
        {
            printf("the greatest number is :%.2f",num1);
        }
    }

    else if(num3>num2)
    {
        printf("the greatest number is %.2f",num3);
    }
    else
    printf("the greatest number is %.2f",num2);


    return 0;
}
