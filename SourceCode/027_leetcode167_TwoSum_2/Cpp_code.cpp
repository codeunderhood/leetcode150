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

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            return {left + 1, right + 1}; // 1-based indexing
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    return {}; // should never reach here as per problem guarantee
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);

    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
