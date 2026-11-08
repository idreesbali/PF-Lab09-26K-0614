#include <stdio.h>

void PrintHall2(int *rows[], int len[])
{
    int vacant = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < len[i]; j++)
        {
            if (*(rows[i] + j) == 1)
            {
                printf("X ");
            }
            else
            {
                printf("_ ");
                vacant++;
            }
        }
        printf("\n");
    }
    printf("Vacant Seats: %d\n", vacant);
}

void Book(int *rows[], int len[])
{
    int row, seat;

    printf("Enter row (1-3): ");
    scanf("%d", &row);
    printf("Enter seat number: ");
    scanf("%d", &seat);

    if (row < 1 || row > 3)
    {
        printf("Invalid: row %d does not exist.\n", row);
        return;
    }

    if (seat < 1 || seat > len[row - 1])
    {
        printf("Invalid: row %d has only %d seats, seat %d does not exist.\n", row, len[row - 1], seat);
        return;
    }

    if (*(rows[row - 1] + (seat - 1)) == 1)
    {
        printf("Invalid: row %d seat %d is already booked.\n", row, seat);
        return;
    }

    *(rows[row - 1] + (seat - 1)) = 1;
    printf("Booking successful: row %d seat %d.\n", row, seat);
    printf("Updated Hall 2:\n");
    PrintHall2(rows, len);
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

    int vacant1 = 0;

    printf("Hall 1:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < 4; j++)
        {
            if (*(*(ptr_hall1 + i) + j) == 1)
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

    printf("Hall 2:\n");
    PrintHall2(ptr_hall2, len2);

    Book(ptr_hall2, len2);

    return 0;
}