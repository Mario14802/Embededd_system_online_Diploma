#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,ele,num=0,loc=0;

    int a[10];

    // Scan matrix a
    printf("Enter number of elements in the matrix:\n");
    scanf("%d",&ele);


    for (i = 0; i < ele; i++)
    {

        printf("enter %d : ", i+1);
        scanf("%d", &a[i]);
        printf("\n");
    }



    printf("Enter the number you want to insert a:\n");
    scanf("%d",&num);

    printf("Enter the location a:\n");
    scanf("%d",&loc);

    for (i = ele - 1; i >= loc-1; i--)
    {
        a[i + 1] = a[i];
    }
    a[loc-1]=num;

    printf("Matrix a:\n");
    for (i = 0; i < ele+1; i++)
    {
        printf("%d ", a[i]);

        printf("\n");
    }

    return 0;
}
