#include <stdio.h>
int Total(int arr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
}
int Highest(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int Lowest(int arr[], int size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int PassCount(int arr[], int size, int thresh)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= thresh)
        {
            count++;
        }
    }
    return count;
}
int TopScorers(int highest, int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == highest)
        {
            count++;
        }
    }
    return count;
}
void ApplyBonus(int bonus, int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] += bonus;
        if (arr[i] > 100)
        {
            arr[i] = 100;
        }
    }
}
int main()
{
    int marks[10];
    int size = sizeof(marks) / sizeof(marks[0]);
    for (int i = 0; i < size; i++)
    {

        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks[i]);
        while (marks[i] < 0 || marks[i] > 100)
        {
            printf("Please enter the marks again for student %d: ", i + 1);
            scanf("%d", &marks[i]);
        }
    }
    printf("Enter threshold: ");
    int threshold;
    scanf("%d", &threshold);
    int total = Total(marks, size);
    printf("Total: %d\n", total);
    float average = (float)total / size;
    printf("Average: %.2f\n", average);
    printf("Highest: %d\n", Highest(marks, size));
    printf("Lowest: %d\n", Lowest(marks, size));
    printf("Pass Count: %d\n", PassCount(marks, size, threshold));
    printf("Top Scorers Count: %d\n", TopScorers(Highest(marks, size), marks, size));
    printf("Bonus marks to be awarded: ");
    int bonus;
    scanf("%d", &bonus);
    ApplyBonus(bonus, marks, size);
    printf("\nAfter Adding Bonus: \n");
    total = Total(marks, size);
    printf("Total: %d\n", total);
    average = (float)total / size;
    printf("Average: %.2f\n", average);
    printf("Highest: %d\n", Highest(marks, size));
    printf("Lowest: %d\n", Lowest(marks, size));
    printf("Pass Count: %d\n", PassCount(marks, size, threshold));
    printf("Top Scorers Count: %d\n", TopScorers(Highest(marks, size), marks, size));
    return 0;
}