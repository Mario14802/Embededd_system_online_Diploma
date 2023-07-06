#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i,n;
    int a[100];


    // Scan matrix a
    printf("Enter the number of elements from  a:\n");
    scanf("%d", &n);
    fflush(stdout);
    fflush(stdin);
    float sum=0;
    for (i = 0; i < n; i++)
    {

        printf("enter number : %d = ", i+1);
        scanf("%d", &a[i]);
        sum +=a[i];


    }
float avg =(sum/n);
    // Print matrix a
    printf("the avg =%.2f\n",avg);

    return 0;
}
