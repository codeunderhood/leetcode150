/*
  Algorithm Steps
1. Initialize:
    left = 0
    right = n - 1
2. While left < right:
    Compute sum = numbers[left] + numbers[right]
3. Compare:
    If sum == target → return result
    If sum < target → left++, as array is sorted and left(smaller) element should be increased to get sum nearby target
    If sum > target → right--,  as array is sorted and right(larger) element should be reduced to get sum nearby target
*/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;

    int* result = (int*)malloc(2 * sizeof(int));

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            result[0] = left + 1;   // 1-based index
            result[1] = right + 1;
            *returnSize = 2;
            return result;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    *returnSize = 0;
    return result;
}

int main() {
    int numbers[] = {2, 7, 11, 15};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int target = 9;

    int returnSize;

    int* result = twoSum(numbers, n, target, &returnSize);

    printf("Output: [%d, %d]\n", result[0], result[1]);

    free(result);

    return 0;
}
