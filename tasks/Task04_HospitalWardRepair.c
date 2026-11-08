#include <stdio.h>
void BadRepair(int a, int b)
{
    printf("  Inside BadRepair: address of a = %p, address of b = %p\n", (void *)&a, (void *)&b);
    int temp = a;
    a = b;
    b = temp;
}
void Repair(int *ptrA, int *ptrB)
{
    printf("  Inside Repair: ptrA = %p, ptrB = %p\n", (void *)ptrA, (void *)ptrB);
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}
void Analyze(int *ptr, int size, int *max, int *low, int *total)
{
    printf("  Inside Analyze: ptr = %p, max = %p, low = %p, total = %p\n",
           (void *)ptr, (void *)max, (void *)low, (void *)total);
    for (int i = 0; i < size; i++)
    {
        *total += *(ptr + i);
        if (*(ptr + i) > *max)
        {
            *max = *(ptr + i);
        }
        if (*(ptr + i) < *low)
        {
            *low = *(ptr + i);
        }
    }
}
int main()
{
    int WardA = 12;
    int WardB = 30;
    printf("Before:   Ward A: %d    Ward B: %d\n", WardA, WardB);
    printf("In main: address of WardA = %p, WardB = %p\n", (void *)&WardA, (void *)&WardB);
    Repair(&WardA, &WardB);
    printf("After:   Ward A: %d    Ward B: %d\n", WardA, WardB);
    int WardC = 40;
    int WardD = 15;
    printf("Junior before: WardC = %d, WardD = %d\n", WardC, WardD);
    printf("In main: address of WardC = %p, WardD = %p\n", (void *)&WardC, (void *)&WardD);
    BadRepair(WardC, WardD);
    printf("Junior after:  WardC = %d, WardD = %d\n", WardC, WardD);
    int daily[7] = {1, 2, 3, 4, 5, 6, 7};
    int high = daily[0], low = daily[0], total = 0;
    printf("In main: daily = %p, high = %p, low = %p, total = %p\n",
           (void *)daily, (void *)&high, (void *)&low, (void *)&total);
    Analyze(daily, 7, &high, &low, &total);
    printf("Highest: %d\n", high);
    printf("Lowest: %d\n", low);
    printf("Total: %d\n", total);
    return 0;
}