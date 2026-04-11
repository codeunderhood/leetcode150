#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // position to place non-val elements
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

/* Test */
int main() {
    int nums[] = {0,1,2,2,3,0,4,2};
    int val = 2;
    int n = 8;

    int k = removeElement(nums, n, val);

    printf("k = %d\n", k);
    printf("Array after removal: ");

    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
