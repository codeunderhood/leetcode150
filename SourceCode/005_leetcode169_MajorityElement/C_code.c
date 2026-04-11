#include <stdio.h>
// 👉 Optimal solution uses Boyer-Moore Voting Algorithm

int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            candidate = nums[i];
            count = 1;
        }
    }

    return candidate;
}

/* Test */
int main() {
    int nums[] = {2,2,1,1,1,2,2};
    int n = 7;

    int ans = majorityElement(nums, n);

    printf("Majority Element: %d\n", ans);

    return 0;
}
