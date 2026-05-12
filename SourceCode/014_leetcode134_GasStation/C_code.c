#include <stdio.h>

int canCompleteCircuit(int gas[], int cost[], int n)
{
    int totalGas = 0;
    int currentGas = 0;
    int start = 0;

    for(int i = 0; i < n; i++)
    {
        int diff = gas[i] - cost[i];

        totalGas += diff;
        currentGas += diff;

        // If petrol becomes negative
        if(currentGas < 0)
        {
            start = i + 1;
            currentGas = 0;
        }
    }

    // If total gas is less than total cost
    if(totalGas < 0)
        return -1;

    return start;
}

int main()
{
    int gas[] = {1,2,3,4,5};
    int cost[] = {3,4,5,1,2};

    int n = sizeof(gas) / sizeof(gas[0]);

    int answer = canCompleteCircuit(gas, cost, n);

    printf("Starting Station = %d\n", answer);

    return 0;
}
