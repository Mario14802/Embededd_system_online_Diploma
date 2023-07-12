#include <stdio.h>
#include <stdlib.h>
int fun(int num);

int main()
{
    int num, fact;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    fact = fun(num);
    printf("Factorial of %d is %d\n", num, fact);
    return 0;
}

int fun(int num)
{
    int fact;
    if (num == 0) { // base case
        fact = 1;
    } else {
        fact = num * fun(num-1); // recursive call
    }
    return fact;
}
