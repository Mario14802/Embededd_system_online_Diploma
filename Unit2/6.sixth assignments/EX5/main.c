#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[50];
    int id;
};

int main() {
    struct Employee *emp[5];
    struct Employee emp1 = {"Alex", 1002};
    emp[0] = &emp1;
    printf("Employee Name : %s\n", (*emp)->name);
    printf("Employee ID : %d\n", (*emp)->id);
    return 0;
}
