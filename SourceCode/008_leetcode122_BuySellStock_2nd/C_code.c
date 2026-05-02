#include <stdio.h>

int maxProfit(int prices[], int n) {
    int profit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, n);
    printf("Maximum Profit = %d\n", result);

    return 0;
}
