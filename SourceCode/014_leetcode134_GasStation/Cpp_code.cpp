#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int totalGas = 0;
    int currentGas = 0;
    int start = 0;

    for(int i = 0; i < gas.size(); i++)
    {
        int diff = gas[i] - cost[i];

        totalGas += diff;
        currentGas += diff;

        if(currentGas < 0)
        {
            start = i + 1;
            currentGas = 0;
        }
    }

    if(totalGas < 0)
        return -1;

    return start;
}

int main()
{
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << "Starting Station = "
         << canCompleteCircuit(gas, cost);

    return 0;
}
