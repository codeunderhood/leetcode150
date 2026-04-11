#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int i = m - 1;        // last valid element in nums1
    int j = n - 1;        // last element in nums2
    int k = m + n - 1;    // last position in nums1

    // Merge from back to avoid overwriting nums1 values
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements of nums2 (if any)
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

/* Optional test driver */
int main() {
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2,5,6};

    merge(nums1, 3, nums2, 3);

    for (int i = 0; i < 6; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
