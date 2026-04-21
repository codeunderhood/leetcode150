#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxArea(int height[], int n) {
    int left = 0;
    int right = n - 1;
    int maxArea = 0;

    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = h * width;

        maxArea = max(maxArea, area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(height) / sizeof(height[0]);

    printf("Maximum water: %d\n", maxArea(height, n));

    return 0;
}
