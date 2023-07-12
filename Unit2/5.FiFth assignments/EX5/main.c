#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main()
{
    int r;
    printf("Enter the radius: ");
    scanf("%d", &r);

    double area = PI * r * r;
    printf("The area of the circle with radius %d is %.2f\n", r, area);
    return (0);
}
