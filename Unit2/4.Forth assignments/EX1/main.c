#include <stdio.h>
#include <stdlib.h>

void fun(int start,int end);

int main()
{
    int start,end,i;

    printf("Enter 2 numbers:\n");
    scanf("%d",&start);
    printf("\n");
    scanf("%d",&end);

    fun(start,end);


    return 0;
}



 void fun(int start, int end) {
    int i, j;
    for (i = start; i <= end; i++) {
        int isPrime = 1;
        for (j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime && i > 1) {
            printf("%d ", i);
        }
    }
}
