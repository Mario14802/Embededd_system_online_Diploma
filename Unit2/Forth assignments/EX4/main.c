#include <stdio.h>
#include <stdlib.h>
void fun(int num,int power);

int main()
{

    int num,power ;
    printf("Enter base number:\n");
    scanf("%d",&num);

    fflush(stdin);fflush(stdout);

    printf("Enter power number:\n");
    scanf("%d",&power);

    fun(num,power);
    return 0;
}

void fun(int num, int power) {

    int i,res = 1;

    for ( i = 1; i <= power; i++) {
        res *= num;
    }

    printf("The result of %d^%d = %d\n", num, power, res);
}
