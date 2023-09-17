#include <stdio.h>

// Function declarations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main(void)
{
    int choice;
    double num1, num2, result;

    printf("Simple calculator\n");
    printf("----------------\n");

    while (1)
    {
        printf("Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            printf("Goodbye!!\n");
            break;
        }

        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        switch (choice)
        {
        case 1:
            result = add(num1, num2);
            break;
        case 2:
            result = subtract(num1, num2);
            break;
        case 3:
            result = multiply(num1, num2);
            break;
        case 4:
            if (num2 != 0)
            {
                result = divide(num1, num2);
            }
            else
            {
                printf("Error: Division by zero\n");
                continue; // Skip calculation of invalid value
            }
            break;
        default:
            printf("Invalid choice. Try again.\n");
            continue; // Skip calculation of invalid value
        }
        printf("Result: %.2lf\n", result);
    }

    return 0;
}

// Function definitions
double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        printf("Division by zero: Error!!\n");
        return 0;
    }
}
