#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {

        printf("i = %d --> ", i);

        // if current index is beyond maxReach, we are stuck
        if (i > maxReach) {
            printf("cant reach till end \n");
            return false;
        }

        // update farthest reachable index from this position
        int reachFromHere = i + nums[i];

        printf("reachFromHere : %d <-->", reachFromHere);

        if (reachFromHere > maxReach) {
            maxReach = reachFromHere;
            printf("maxReach : %d", maxReach);
        }

        printf("\n");

        // early exit if we already can reach end
        if (maxReach >= numsSize - 1) {
            printf("can reach till end \n");
            return true;
        }
    }

    return true;
}

// ---------------- MAIN ----------------
int main() {

    // ================= SUCCESS CASE =================
    printf("\n===== SUCCESS CASE =====\n");
    int success[] = {4,1,2,0,2,0,1,3,2,1,4};
    int n1 = sizeof(success) / sizeof(success[0]);

    if (canJump(success, n1)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    // ================= FAILURE CASE =================
    printf("\n===== FAILURE CASE =====\n");
    int fail[] = {3,2,1,0,4};
    int n2 = sizeof(fail) / sizeof(fail[0]);

    if (canJump(fail, n2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
