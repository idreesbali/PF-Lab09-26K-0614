#include <stdio.h>
int divError = 0;
void Printing(void *ptr, char type)
{
    if (type == 'i')
    {
        printf("Data: %d\n", *(int *)ptr);
    }
    if (type == 'f')
    {
        printf("Data: %.2f\n", *(float *)ptr);
    }
    if (type == 'c')
    {
        printf("Data: %c\n", *(char *)ptr);
    }
}
int add(int n1, int n2)
{
    return n1 + n2;
}
int sub(int n1, int n2)
{
    return n1 - n2;
}
int prod(int n1, int n2)
{
    return n1 * n2;
}
int division(int n1, int n2)
{
    if (n2 == 0)
    {
        divError = 1;
        return 0;
    }
    return n1 / n2;
}
int calculation(int n1, int n2, int (*op)(int, int))
{
    return op(n1, n2);
}
int main()
{
    int age = 20;
    Printing(&age, 'i');
    float height = 5.92;
    Printing(&height, 'f');
    char initial = 'i';
    Printing(&initial, 'c');
    printf("Enter any two number: ");
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int (*operations[4])(int, int) = {add, sub, prod, division};
    printf("1. Addition\n2. Subtraction\n3. Product\n4. Division\nWhat operation do you wanna perform: ");
    int op;
    scanf("%d", &op);
    while (op < 1 || op > 4)
    {
        printf("Enter again: ");
        scanf("%d", &op);
    }
    int result = calculation(n1, n2, operations[op - 1]);
    if (divError == 0)
        printf("Result: %d\n", result);
    else
        printf("Error: Division by zero isn't possible\n");
}