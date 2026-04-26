#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    reverse(nums, 0, n - 1);     // whole array
    reverse(nums, 0, k - 1);     // first k
    reverse(nums, k, n - 1);     // rest
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    rotate(nums, k);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}
