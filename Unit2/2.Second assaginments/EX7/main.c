#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i;
    long long factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial of negative number does not exist.\n");
        return 0;
    }

    for (i = 1; i <= n; i++) {
        factorial *= i;
    }

    printf("Factorial of %d = %ld\n", n, factorial);

    return 0;
}
