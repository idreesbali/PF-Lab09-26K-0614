#include <stdio.h>

void PrintGeneric(void *data, char type)
{
    if (type == 'i')
    {
        printf("%d\n", *(int *)data);
    }
    else if (type == 'f')
    {
        printf("%.2f\n", *(float *)data);
    }
    else if (type == 'c')
    {
        printf("%c\n", *(char *)data);
    }
}

int Add(int a, int b, int *result)
{
    *result = a + b;
    return 1;
}

int Subtract(int a, int b, int *result)
{
    *result = a - b;
    return 1;
}

int Multiply(int a, int b, int *result)
{
    *result = a * b;
    return 1;
}

int Divide(int a, int b, int *result)
{
    if (b == 0)
    {
        return 0;
    }
    *result = a / b;
    return 1;
}

int Calculate(int a, int b, int (*operation)(int, int, int *), int *result)
{
    return operation(a, b, result);
}

int main()
{
    int testInt = 25;
    float testFloat = 3.14159f;
    char testChar = 'A';

    PrintGeneric(&testInt, 'i');
    PrintGeneric(&testFloat, 'f');
    PrintGeneric(&testChar, 'c');

    int (*operations[4])(int, int, int *) = {Add, Subtract, Multiply, Divide};

    int num1, num2, choice, result;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("Choose an operation: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4)
    {
        printf("Invalid choice.\n");
        return 0;
    }

    if (Calculate(num1, num2, operations[choice - 1], &result) == 0)
    {
        printf("Error: division by zero.\n");
        return 0;
    }

    printf("Result: ");
    PrintGeneric(&result, 'i');

    return 0;
}