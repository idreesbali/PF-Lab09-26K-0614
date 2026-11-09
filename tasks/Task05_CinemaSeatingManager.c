#include <stdio.h>
int Booking(int *ptr[])
{
    printf("Booking for Hall 2: \n");
    printf("Row: ");
    int row;
    scanf("%d", &row);
    while (row < 1 || row > 3)
    {
        printf("\nInvalid Input. Try Again: ");
        scanf("%d", &row);
    }
    printf("Seat: ");
    int seat;
    scanf("%d", &seat);
    printf("\n");
    if (row == 1)
    {
        if (seat >= 1 && seat <= 3 && *(ptr[0] + (seat - 1)) == 0)
        {
            *(ptr[0] + (seat - 1)) = 1;
            return 1;
        }
        else
        {
            if (seat < 1 || seat > 3)
            {
                printf("Invalid Seat no.\n");
            }
            else
            {
                printf("Seat is already booked.\n");
            }
            return 0;
        }
    }
    if (row == 2)
    {
        if (seat >= 1 && seat <= 5 && *(ptr[1] + (seat - 1)) == 0)
        {
            *(ptr[1] + (seat - 1)) = 1;
            return 1;
        }
        else
        {
            if (seat < 1 || seat > 5)
            {
                printf("Invalid Seat no.\n");
            }
            else
            {
                printf("Seat is already booked.\n");
            }
            return 0;
        }
    }
    if (row == 3)
    {
        if (seat >= 1 && seat <= 7 && *(ptr[2] + (seat - 1)) == 0)
        {
            *(ptr[2] + (seat - 1)) = 1;
            return 1;
        }
        else
        {
            if (seat < 1 || seat > 7)
            {
                printf("Invalid Seat no.\n");
            }
            else
            {
                printf("Seat is already booked.\n");
            }
            return 0;
        }
    }
    return 0;
}
int main()
{
    int hall1[3][4] =
        {
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0}};
    int hall2_r1[3] = {1, 0, 0};
    int hall2_r2[5] = {0, 0, 1, 1, 0};
    int hall2_r3[7] = {1, 0, 0, 1, 0, 1, 0};
    int (*ptr_hall1)[4] = hall1;
    int *ptr_hall2[3];
    ptr_hall2[0] = hall2_r1;
    ptr_hall2[1] = hall2_r2;
    ptr_hall2[2] = hall2_r3;
    int len2[3] = {3, 5, 7};
    int vacant1 = 0, vacant2 = 0;
    printf("Hall 1: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < 4; j++)
        {
            if ((*(ptr_hall1 + i))[j] == 1)
            {
                printf("X ");
            }
            else
            {
                printf("_ ");
                vacant1++;
            }
        }
        printf("\n");
    }
    printf("Vacant Seats: %d\n", vacant1);
    printf("Hall 2: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < len2[i]; j++)
        {
            if (*(ptr_hall2[i] + j) == 1)
            {
                printf("X ");
            }
            else
            {
                printf("_ ");
                vacant2++;
            }
        }
        printf("\n");
    }
    printf("Vacant Seats: %d\n", vacant2);
    if (Booking(ptr_hall2))
    {
        printf("Booking Successfull\n");
    }
    else
    {
        printf("Booking Unsuccesfull\n");
    }
    vacant2 = 0;
    printf("Hall 2: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < len2[i]; j++)
        {
            if (*(ptr_hall2[i] + j) == 1)
            {
                printf("X ");
            }
            else
            {
                printf("_ ");
                vacant2++;
            }
        }
        printf("\n");
    }
    printf("Vacant Seats: %d", vacant2);
    return 0;
}