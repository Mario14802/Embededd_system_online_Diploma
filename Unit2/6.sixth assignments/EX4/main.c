#include <stdio.h>
#include <string.h>

int main()
{
    int arr[15];
    int *ptr;
    int i;
    int size=5;
    printf("Input an array of 5 integers:\n");

    for (i = 0; i < size; i++)
    {
        printf("Element number: %d\n",i+1);
        scanf("%d", &arr[i]);

    }

    ptr = arr+(size-1) ; // point to the last element

    printf("Reverse of the array is : ");
    while (ptr >= arr)
    {
        printf("%d ", *ptr);
        ptr--;
    }

    return 0;
}
