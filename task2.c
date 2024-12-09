#include <stdio.h>
#include <stdlib.h>

typedef int (*operation_func)(int, int);  // Define a type for function pointers

// Define operations as functions
int add(int a, int b) {
    printf("Adding ‘a’ and ‘b’\n");
    return a + b;
}

int subtract(int a, int b) {
    printf("Subtracting ‘b’ from ‘a’\n");
    return a - b;
}

int multiply(int a, int b) {
    printf("Multiplying ‘a’ and ‘b’\n");
    return a * b;
}

int divide(int a, int b) {
    printf("Dividing ‘a’ by ‘b’\n");
    return a / b;
}

int main() {
    int a = 6, b = 3;
    int operation;
    operation_func operations[] = {add, subtract, multiply, divide};  // Array of function pointers

    // Prompt the user for input
    printf("Operand ‘a’ : %d | Operand ‘b’ : %d\n", a, b);
    printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
    scanf("%d", &operation);

    // Exit condition
    if (operation == 4) {
        printf("Exiting program.\n");
        return 0;
    }

    // Perform the operation using the function pointer
    if (operation >= 0 && operation < 4) {
        int result = operations[operation](a, b);
        printf("x = %d\n", result);
    } else {
        printf("Invalid operation.\n");
    }

    return 0;
}
