#include <stdio.h>

int main()
{
    float a, b, result;
    char operation;
    int successCount = 0;  

    while (1) { 
        printf("Enter a, b and operation (+ or - or * or /, or $ to exit): ");
        scanf(" %f %f %c", &a, &b, &operation);

        if (operation == '$') {
            printf("Program terminated. Total successful calculations: %d\n", successCount);
            break; 
        }

      
        if (operation == '/' && b == 0.0) {
            printf("Error: Cannot divide by 0.0. Operation has failed.\n");
            continue;
        }

        if (operation == '+')
            result = a + b;
        else if (operation == '-')
            result = a - b;
        else if (operation == '*')
            result = a * b;
        else if (operation == '/')
            result = a / b;
        else {
            printf("Error: undefined operation: %c\n", operation);
            continue;
        }

        
        successCount++;
        printf("Success! Result of %.2f %c %.2f = %.2f\n", a, operation, b, result);
    }

    return 0;
}
