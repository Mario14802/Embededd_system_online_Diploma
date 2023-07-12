#include <stdio.h>
#include <stdlib.h>

struct students_data
{
    float feet;
    float inch;


} d1,d2;

int main()
{

    printf("Enter feet value for first distance\n");

    scanf("%f",&d1.feet);
    printf("\n");

    printf("Enter the inches for first distance\n");
    scanf("%f",&d1.inch);
    printf("\n");

    //-----------------------------------

    printf("Enter feet value for second distance\n");

    scanf("%f",&d2.feet);
    printf("\n");

    printf("Enter the inches for second distance\n");
    scanf("%f",&d2.inch);
    printf("\n");

    printf("the feets value for first distance is  :%f\n",d1.feet);
    printf("the rinch value for the first distance is :%f\n\n",d1.inch);
    printf("the feets value for second distance is  :%f\n",d2.feet);
    printf("the rinch value for the second distance is :%f\n",d2.inch);

    float sum =(d1.feet+d2.feet)+((d1.inch+d2.inch)/10);
    printf("the sum is :%.2f",sum);


    return 0;
}
