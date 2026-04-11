#include <iostream>
#include <vector>
using namespace std;
// 👉 Optimal solution uses Boyer-Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }

        return candidate;
    }
};

/* Test */
int main() {
    Solution s;

    vector<int> nums = {3,2,3};

    cout << "Majority Element: " << s.majorityElement(nums);

    return 0;
}
