#include <stdio.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize) 
{
    // Step 1:
    // Create candy array
    int* candies = (int*)malloc(sizeof(int) * ratingsSize);

    // Step 2:
    // Give 1 candy to everyone initially
    for(int i = 0; i < ratingsSize; i++)
    {
        candies[i] = 1;
    }

    // Step 3:
    // Left to Right pass
    for(int i = 1; i < ratingsSize; i++)
    {
        // If current child has higher rating
        // than left child
        if(ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Step 4:
    // Right to Left pass
    for(int i = ratingsSize - 2; i >= 0; i--)
    {
        // If current child has higher rating
        // than right child
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
            int needed = candies[i + 1] + 1;
            if(needed > candies[i])
            {
                candies[i] = needed;
            }
        }
    }

    // Step 5:
    // Calculate total candies
    int total = 0;

    for(int i = 0; i < ratingsSize; i++)
    {
        total += candies[i];
    }

    // Free allocated memory
    free(candies);

    return total;
}

int main()
{
    int ratings[] = {1, 0, 2};
    int n = sizeof(ratings) / sizeof(ratings[0]);

    printf("Minimum candies = %d\n", candy(ratings, n));

    return 0;
}
