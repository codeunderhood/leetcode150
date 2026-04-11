#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int k = 2;

        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

/* Test */
int main() {
    Solution s;

    vector<int> nums = {0,0,1,1,1,1,2,3,3};

    int k = s.removeDuplicates(nums);

    cout << "k = " << k << endl;
    cout << "Array after processing: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
