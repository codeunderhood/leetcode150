#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) 
{
    int n = ratings.size();

    vector<int> candies(n, 1);

    // Left to Right
    for(int i = 1; i < n; i++)
    {
        if(ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to Left
    for(int i = n - 2; i >= 0; i--)
    {
        if(ratings[i] > ratings[i + 1])
        {
            // only update candies when "needed" is more than current "candies[i]" count
          // for example if after left pass - candies become [1,2,3,1]
          // then if we simply write below code for right pass - similar to left pass
          //  if(ratings[i] > ratings[i + 1]) 
          //    { candies[i] = candies[i + 1] + 1 ; } --> THIS DESTROYS PREVIOUS VALUE AND BECOMES candies[1,2,2,1] violating left pass rule
          // Hence below logic is needed, to make sure, left and right pass both validate rule.
          // right pass rule, should not violate the left pass rule
            // Take maximum to preserve left pass result
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int total = 0;

    for(int x : candies)
    {
        total += x;
    }

    return total;
}

int main()
{
    vector<int> ratings = {1,0,2};

    cout << "Minimum candies = "
         << candy(ratings);

    return 0;
}
