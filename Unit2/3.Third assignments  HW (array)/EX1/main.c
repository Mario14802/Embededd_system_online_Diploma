#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c;
    int a[2][2];
    int b[2][2];

    // Scan matrix a
    printf("Enter values for matrix a:\n");
    for (r = 0; r < 2; r++)
    {
        for (c = 0; c < 2; c++)
        {
            printf("a[%d][%d] = ", r, c);
            scanf("%d", &a[r][c]);
        }
    }

    // Print matrix a
    printf("Matrix a:\n");
    for (r = 0; r < 2; r++)
    {
        for (c = 0; c < 2; c++)
        {
            printf("%d ", a[r][c]);
        }
        printf("\n");
    }

    // Scan matrix b
    printf("Enter values for matrix b:\n");
    for (r = 0; r < 2; r++)
    {
        for (c = 0; c < 2; c++)
        {
            printf("b[%d][%d] = ", r, c);
            scanf("%d", &b[r][c]);
        }
    }

    // Print matrix b
    printf("Matrix b:\n");
    for (r = 0; r < 2; r++)
    {
        for (c = 0; c < 2; c++)
        {
            printf("%d ", b[r][c]);
        }
        printf("\n");
    }



    // Print matrix b
    printf("Matrix a+b:\n");
    for (r = 0; r < 2; r++)
    {
        for (c = 0; c < 2; c++)
        {

            printf("%d ", (b[r][c]+a[r][c]));
        }
        printf("\n");
    }


    return 0;
}
