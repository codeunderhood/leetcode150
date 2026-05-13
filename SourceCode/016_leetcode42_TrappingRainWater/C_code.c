#include <stdio.h>

int trap(int height[], int n) {

    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int totalWater = 0;

    while(left < right) {

        // LEFT SIDE SMALLER
        if(height[left] < height[right]) {

            // UPDATE leftMax
            if(height[left] >= leftMax) {
                leftMax = height[left];
            }
            else {

                // WATER TRAPPED
                totalWater +=
                    leftMax - height[left];
            }

            left++;
        }

        // RIGHT SIDE SMALLER
        else {

            // UPDATE rightMax
            if(height[right] >= rightMax) {
                rightMax = height[right];
            }
            else {

                // WATER TRAPPED
                totalWater +=
                    rightMax - height[right];
            }

            right--;
        }
    }

    return totalWater;
}

int main() {

    int height[] =
        {0,1,0,2,1,0,1,3,2,1,2,1};

    int n =
        sizeof(height)/sizeof(height[0]);

    int ans = trap(height, n);

    printf("Total Water = %d\n", ans);

    return 0;
}
