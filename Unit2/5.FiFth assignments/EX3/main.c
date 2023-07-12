#include <stdio.h>
#include <stdlib.h>

struct students_data
{
    float real;
    float imaginary;


} n1,n2;

int main()
{

    printf("Enter  value of real_num for first complex number\n");

    scanf("%f",&n1.real);
    printf("\n");

    printf("Enter value for imaginary_num for first complex number\n");
    scanf("%f",&n1.imaginary);
    printf("\n");

    //-----------------------------------

     printf("Enter  value of real_num for second complex number\n");

    scanf("%f",&n2.real);
    printf("\n");

    printf("Enter value for imaginary_num for second complex number\n");
    scanf("%f",&n2.imaginary);
    printf("\n");



    float sum_real =(n1.real+n2.real);
    float sum_imaginary =(n1.imaginary+n2.imaginary);
    printf("the sum of numbers is  is :%.2f + %.2fi",sum_real,sum_imaginary);


    return 0;
}
