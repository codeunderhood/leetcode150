#include <stdio.h>

int jump(int* nums, int numsSize) {
    int jumps = 0;
    int rangeEnd = 0;
    int farthest = 0;

    for (int i = 0; i < numsSize - 1; i++) {

        if (i + nums[i] > farthest) {
            farthest = i + nums[i];
        }

        if (i == rangeEnd) {
            jumps++;
            rangeEnd = farthest;
        }
    }

    return jumps;
}

int main() {

    // ✅ BIG SUCCESS CASE
    int success[] = {3, 4, 2, 1, 2, 1, 5, 2, 1, 1, 2, 3, 1, 1, 4};
    int n1 = sizeof(success) / sizeof(success[0]);

    printf("SUCCESS CASE (Big Array):\n");
    printf("Minimum jumps = %d\n\n", jump(success, n1));

    // ❌ FAILURE CASE (for learning)
    int fail[] = {3, 2, 1, 0, 0, 1, 2, 3};
    int n2 = sizeof(fail) / sizeof(fail[0]);

    printf("FAILURE CASE:\n");
    printf("Minimum jumps = %d\n", jump(fail, n2));

    return 0;
}
