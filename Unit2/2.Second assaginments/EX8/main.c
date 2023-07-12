#include <stdio.h>
#include <stdlib.h>

int main() {
    float num1, num2, result;
    char op;

    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter second number: ");
    scanf("%f", &num2);

    if (op == '+') {
        result = num1 + num2;
        printf("%.2f + %.2f = %.2f\n", num1, num2, result);
    }
    else if (op == '-') {
        result = num1 - num2;
        printf("%.2f - %.2f = %.2f\n", num1, num2, result);
    }
    else if (op == '*') {
        result = num1 * num2;
        printf("%.2f * %.2f = %.2f\n", num1, num2, result);
    }
    else if (op == '/') {
        if (num2 == 0) {
            printf("Error: Division by zero\n");
            return 0;
        }
        else {
            result = num1 / num2;
            printf("%.2f / %.2f = %.2f\n", num1, num2, result);
        }
    }
    else {
        printf("Error: Invalid operator\n");
    }

    return 0;
}
