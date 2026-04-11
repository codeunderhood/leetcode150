#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int k = 1; // first element is always unique

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

/* Test */
int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int n = 10;

    int k = removeDuplicates(nums, n);

    printf("k = %d\n", k);
    printf("Array after removing duplicates: ");

    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
