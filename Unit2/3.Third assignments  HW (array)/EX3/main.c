#include <stdio.h>
#include <stdlib.h>

int main()
{

    int r,c,n,R,C;

   int a[5][5];

    // Scan matrix a
    printf("Enter rows:\n");
    scanf("%d",&R);
    printf("Enter colums:\n");
    scanf("%d",&C);



    for (r = 0; r < R; r++)
    {
        for (c= 0; c < C; c++)
        {
            printf("enter a[%d][%d] : ", r, c);
            scanf("%d", &a[r][c]);
        }
    }

    // Print matrix a
    printf("Matrix a:\n");
    for (r = 0; r < R; r++)
    {
        for (c = 0; c < C; c++)
        {
            printf("%d ", a[r][c]);
        }
        printf("\n");
    }

     int transpose[5][5];
    for (c = 0; c < C; c++)
    {
        for (r = 0; r < R; r++)
        {
            transpose[c][r] = a[r][c];
        }
    }

    // Print transpose of matrix a
    printf("Transpose of matrix a:\n");
    for (c = 0; c < C; c++)
    {
        for (r = 0; r < R; r++)
        {
            printf("%d ", transpose[c][r]);
        }
        printf("\n");
    }

    return 0;
}
