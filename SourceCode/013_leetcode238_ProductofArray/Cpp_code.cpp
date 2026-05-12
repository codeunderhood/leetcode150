#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

    int n = nums.size();

    vector<int> answer(n);

    // Prefix products
    answer[0] = 1;

    for(int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Suffix products
    int rightProduct = 1;

    for(int i = n - 1; i >= 0; i--) {

        answer[i] *= rightProduct;

        rightProduct *= nums[i];
    }

    return answer;
}

int main() {

    vector<int> nums = {1,2,3,4};

    vector<int> result = productExceptSelf(nums);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}
