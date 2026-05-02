#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {

        // Update minPrice if we find a smaller value
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        // Otherwise compute profit and update maxProfit if better
        else {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}

// Example usage
int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    printf("Max Profit: %d\n", maxProfit(prices, n));
    return 0;
}
