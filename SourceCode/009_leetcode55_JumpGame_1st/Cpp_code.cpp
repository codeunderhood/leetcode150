#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;

    for (int i = 0; i < nums.size(); i++) {

        // if we cannot even reach this index
        if (i > maxReach) {
            return false;
        }

        // update farthest reachable index
        int reachFromHere = i + nums[i];
        if (reachFromHere > maxReach) {
            maxReach = reachFromHere;
        }

        // early exit
        if (maxReach >= nums.size() - 1) {
            return true;
        }
    }

    return true;
}

int main() {
    vector<int> nums = {4,1,2,0,2,0,1,3,2,1,4};

    cout << (canJump(nums) ? "true" : "false") << endl;

    return 0;
}
