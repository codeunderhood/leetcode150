#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize;

    int k = 2; // first two elements are always allowed

    for (int i = 2; i < numsSize; i++) {
        if (nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

/* Test */
int main() {
    int nums[] = {1,1,1,2,2,3};
    int n = 6;

    int k = removeDuplicates(nums, n);

    printf("k = %d\n", k);
    printf("Array after processing: ");

    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
