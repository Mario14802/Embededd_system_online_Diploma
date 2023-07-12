#include <stdio.h>
#include <stdlib.h>

struct students_data
{
    char name[10];
    float marks;
    int roll_number;

} st[10];

int main()
{
    while(1){

        int i;
            for(i=0;i<=10;i++){
    printf("Enter the data of the  student number:%d\n\n",i+1);
    printf("Enter the name max 10 char\n");

    scanf("%s",&st[i].name);
    printf("\n");

    printf("Enter the roll number\n");
    scanf("%d",&st[i].roll_number);
    printf("\n");

    printf("Enter the Marks\n");
    scanf("%f",&st[i].marks);
    printf("\n");

    printf("the name is :%s\n",st[i].name);
    printf("the roll number is :%d\n",st[i].roll_number);
    printf("the marks is :%.2f\n",st[i].marks);
     printf("\n");
            }
    }
    return 0;
}
