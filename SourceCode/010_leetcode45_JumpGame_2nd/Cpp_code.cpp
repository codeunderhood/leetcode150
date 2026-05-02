#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0;
    int rangeEnd = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++) {

        farthest = max(farthest, i + nums[i]);

        if (i == rangeEnd) {
            jumps++;
            rangeEnd = farthest;
        }
    }

    return jumps;
}

int main() {

    // ✅ BIG SUCCESS CASE
    vector<int> success = {3, 4, 2, 1, 2, 1, 5, 2, 1, 1, 2, 3, 1, 1, 4};

    cout << "SUCCESS CASE (Big Array):\n";
    cout << "Minimum jumps = " << jump(success) << "\n\n";

    // ❌ FAILURE CASE (learning example)
    vector<int> fail = {3, 2, 1, 0, 0, 1, 2, 3};

    cout << "FAILURE CASE:\n";
    cout << "Minimum jumps = " << jump(fail) << "\n";

    return 0;
}
