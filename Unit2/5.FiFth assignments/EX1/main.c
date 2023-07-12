#include <stdio.h>
#include <stdlib.h>

struct students_data
{
    char name[10];
    float marks;
    int roll_number;

} st1;

int main()
{
    printf("Enter the data of the first student\n\n");
    printf("Enter the name max 10 char\n");

    scanf("%s",&st1.name);
    printf("\n");

    printf("Enter the roll number\n");
    scanf("%d",&st1.roll_number);
    printf("\n");

    printf("Enter the Marks\n");
    scanf("%f",&st1.marks);
    printf("\n");

    printf("the name is :%s\n",st1.name);
    printf("the roll number is :%d\n",st1.roll_number);
    printf("the marks is :%.2f\n",st1.marks);
    return 0;
}
