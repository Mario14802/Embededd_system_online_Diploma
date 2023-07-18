#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=29 ;

    int*ptr=&num;

    printf("the address of m:%p\n of the value of m:%d\n\n",&num,num);

    printf("the address of ab:%p\n of the value of ab:%d\n\n",ptr,*ptr);

    *ptr=34;

    printf("the address of ab:%p\n of the value of ab:%d\n\n",ptr,*ptr);

    *ptr=7;

    printf("the address of ab:%p\n of the value of ab:%d\n\n",ptr,*ptr);





    return 0;
}
