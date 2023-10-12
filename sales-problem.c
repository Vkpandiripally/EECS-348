#include <stdio.h>

const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void generate_sales_report(float sales[], int size) {
    printf("Monthly sales report for 2023:\n");
    printf("Month     Sales\n");
    int width = 10;
    for (int month = 0; month < size; ++month) {
        printf("%-*s $%.2f\n",width, months[month], sales[month]);
    }
}

void salesSummary(float sales[], int size) {
    float min = sales[0], max = sales[0], total = sales[0];
    int minMonth = 0, maxMonth = 0;
    double average;
    for (int i = 1; i < size; ++i) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        total += sales[i];
    }
    average = total / size;
    printf("\nSales summary:\n");
    printf("Minimum Sales: $%.2f (%s)\n", min, months[minMonth]);
    printf("Maximum Sales: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Average Sales: $%.2f\n", average);
}

void sixMonthMovingAverage(float sales[], int size) {
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= size - 6; ++i) {
        float sum = 0;
        for (int j = i; j < i + 6; ++j) {
            sum += sales[j];
        }
        double average = sum / 6;
        int width = 10;
        printf("%-*s - %s $%-*.2f\n", width, months[i], months[i + 5], average);
    }
}

void salesReportHightoLow(float sales[], int size) {
    printf("\nMonthly Sales Report (Highest to Lowest):\n");
    // Create an array of indices to keep track of original positions
    int indices[size];
    for (int i = 0; i < size; ++i) {
        indices[i] = i;
    }
    // Sort indices based on sales data
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (sales[i] < sales[j]) {
                // Swap indices
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    // Print sales data in sorted order
    int width=10;
    for (int month = 0; month < size; ++month) {
        printf("%-*s $%5.2f\n",width, months[indices[month]], sales[indices[month]]);
    }
}

int main() {
    float sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    generate_sales_report(sales, 12);
    salesSummary(sales, 12);
    sixMonthMovingAverage(sales, 12);
    salesReportHightoLow(sales, 12);
    return 0;
}
