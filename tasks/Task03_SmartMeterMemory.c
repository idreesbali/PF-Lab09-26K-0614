#include <stdio.h>
int main()
{
    int reading[7];
    int *ptr;
    ptr = reading;
    for (int i = 0; i < 7; i++)
    {
        printf("Enter reading %d: ", i + 1);
        scanf("%d", ptr + i);
    }
    printf("Please enter threshold: ");
    int thresh;
    scanf("%d", &thresh);
    for (int i = 0; i < 7; i++)
    {
        printf("Reading %d:     Value: %d   Address: %p\n", i + 1, *(ptr + i), (ptr + i));
    }
    printf("Their memory is far apart by: %td\n", (char *)(ptr + 1) - (char *)(ptr));
    printf("Why: each reading is an int, and an int takes %zu bytes.\n", sizeof(int));
    int total = 0, max = *ptr, day = 1;

    for (int i = 0; i < 7; i++)
    {
        total += *(ptr + i);
        if (*(ptr + i) > max)
        {
            max = *(ptr + i);
            day = i + 1;
        }
    }

    printf("Weekly Total: %d\n", total);
    printf("Day: %d   with highest consumption: %d\n", day, max);

    for (int i = 0; i < 7; i++)
    {
        if (*(ptr + i) > thresh)
        {
            *(ptr + i) *= 2;
        }
    }

    printf("After peak tariff: ");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", *(ptr + i));
    }
    int *linked = NULL;

    for (int round = 1; round <= 2; round++)
    {
        if (round == 2)
        {
            linked = ptr + 2;
        }

        if (linked != NULL)
        {
            printf("Linked meter reading: %d\n", *linked);
        }
        else
        {
            printf("Linked meter is not assigned yet.\n");
        }
    }
    return 0;
}