#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {

        // if current index is beyond maxReach, we are stuck
        if (i > maxReach) {
            return false;
        }

        // update farthest reachable index from this position
        int reachFromHere = i + nums[i];
        if (reachFromHere > maxReach) {
            maxReach = reachFromHere;
        }

        // early exit if we already can reach end
        if (maxReach >= numsSize - 1) {
            return true;
        }
    }

    return true;
}

// Example usage
int main() {
    int nums[] = {4,1,2,0,2,0,1,3,2,1,4};
    int n = sizeof(nums) / sizeof(nums[0]);

    if (canJump(nums, n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
