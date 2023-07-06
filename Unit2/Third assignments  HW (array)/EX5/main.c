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
        printf("\r");
    }



    printf("Enter the number you want to Search for :\n");
    scanf("%d",&num);

   for(i=0;i<ele;i++)
   {
       if(num==a[i])
        {
            printf("the location is %d",i+1);
       break;
        }

   }




    return 0;
}
