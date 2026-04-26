#include <stdio.h>

void reverse(int nums[], int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int nums[], int n, int k) {
    k = k % n;

    reverse(nums, 0, n - 1);     // reverse whole array
    reverse(nums, 0, k - 1);     // reverse first k elements
    reverse(nums, k, n - 1);     // reverse remaining elements
}

int main() {
    int nums[] = {1,2,3,4,5,6,7};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    rotate(nums, n, k);

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
