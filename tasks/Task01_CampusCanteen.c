#include <stdio.h>

int ValidPrice(double price);
int ValidQty(int qty);
double ItemCost(double price, int qty);
double Subtotal(double cost1, double cost2);
double DiscountAmount(double subtotal);
double FinalTotal(double subtotal, double discount);
int HigherPriceItem(double price1, double price2);

int main()
{
    double price1, price2;
    int qty1, qty2;

    printf("Enter price of item 1: ");
    scanf("%lf", &price1);
    while (!ValidPrice(price1))
    {
        printf("Price cannot be negative. Enter again: ");
        scanf("%lf", &price1);
    }

    printf("Enter quantity of item 1: ");
    scanf("%d", &qty1);
    while (!ValidQty(qty1))
    {
        printf("Quantity cannot be negative. Enter again: ");
        scanf("%d", &qty1);
    }

    printf("Enter price of item 2: ");
    scanf("%lf", &price2);
    while (!ValidPrice(price2))
    {
        printf("Price cannot be negative. Enter again: ");
        scanf("%lf", &price2);
    }

    printf("Enter quantity of item 2: ");
    scanf("%d", &qty2);
    while (!ValidQty(qty2))
    {
        printf("Quantity cannot be negative. Enter again: ");
        scanf("%d", &qty2);
    }

    double cost1 = ItemCost(price1, qty1);
    double cost2 = ItemCost(price2, qty2);
    double subtotal = Subtotal(cost1, cost2);
    double discount = DiscountAmount(subtotal);
    double total = FinalTotal(subtotal, discount);
    int higher = HigherPriceItem(price1, price2);

    printf("\n========== RECEIPT ==========\n");
    printf("Item 1: Rs. %.2f x %d = Rs. %.2f\n", price1, qty1, cost1);
    printf("Item 2: Rs. %.2f x %d = Rs. %.2f\n", price2, qty2, cost2);
    printf("-----------------------------\n");
    printf("Subtotal:       Rs. %.2f\n", subtotal);
    printf("Discount given: Rs. %.2f\n", discount);
    printf("Total to pay:   Rs. %.2f\n", total);
    printf("=============================\n");

    if (higher == 1)
    {
        printf("Item 1 has the higher unit price.\n");
    }
    else if (higher == 2)
    {
        printf("Item 2 has the higher unit price.\n");
    }
    else
    {
        printf("Both items have the same unit price.\n");
    }

    return 0;
}

int ValidPrice(double price)
{
    return price >= 0;
}

int ValidQty(int qty)
{
    return qty >= 0;
}

double ItemCost(double price, int qty)
{
    return price * qty;
}

double Subtotal(double cost1, double cost2)
{
    return cost1 + cost2;
}

double DiscountAmount(double subtotal)
{
    if (subtotal > 1000)
    {
        return subtotal * 0.10;
    }
    return 0;
}

double FinalTotal(double subtotal, double discount)
{
    return subtotal - discount;
}

int HigherPriceItem(double price1, double price2)
{
    if (price1 > price2)
    {
        return 1;
    }
    if (price2 > price1)
    {
        return 2;
    }
    return 0;
}