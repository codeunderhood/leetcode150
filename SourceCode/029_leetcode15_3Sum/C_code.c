#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 3Sum function
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int capacity = 1000;
    int **result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {

        // skip duplicate i
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result[*returnSize] = (int*)malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                left++;
                right--;

                // skip duplicates for left and right
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}

// helper to print result
void printResult(int** res, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("[%d,%d,%d]", res[i][0], res[i][1], res[i][2]);
        if (i < size - 1) printf(",");
    }
    printf("]\n");
}

int main() {
    int returnSize;
    int *returnColumnSizes;

    // ---------------- TEST CASE 1 (Given in question) ----------------
    int nums1[] = {-1, 0, 1, 2, -1, -4};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);

    int** res1 = threeSum(nums1, n1, &returnSize, &returnColumnSizes);

    printf("Test Case 1 Output:\n");
    printResult(res1, returnSize);

    // ---------------- TEST CASE 2 (forced duplicates) ----------------
    // includes:
    // - duplicate i values (-2, -2)
    // - duplicate left/right values (0,0 and 2,2)
    int nums2[] = {-2, -2, 0, 0, 2, 2, 2, -2};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);

    int** res2 = threeSum(nums2, n2, &returnSize, &returnColumnSizes);

    printf("\nTest Case 2 Output:\n");
    printResult(res2, returnSize);

    return 0;
}
