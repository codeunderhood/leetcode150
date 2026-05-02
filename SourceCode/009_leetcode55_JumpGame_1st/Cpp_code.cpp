#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;

    for (int i = 0; i < nums.size(); i++) {

        cout << "i = " << i << " --> ";

        // if current index is beyond maxReach, we are stuck
        if (i > maxReach) {
            cout << "cant reach till end" << endl;
            return false;
        }

        // update farthest reachable index from this position
        int reachFromHere = i + nums[i];

        cout << "reachFromHere : " << reachFromHere;

        if (reachFromHere > maxReach) {
            maxReach = reachFromHere;
            cout << " <--> maxReach : " << maxReach;
        }

        cout << endl;

        // early exit if we already can reach end
        if (maxReach >= nums.size() - 1) {
            cout << "can reach till end" << endl;
            return true;
        }
    }

    return true;
}

int main() {

    // ================= SUCCESS CASE =================
    cout << "\n===== SUCCESS CASE =====\n";
    vector<int> success = {4,1,2,0,2,0,1,3,2,1,4};

    if (canJump(success)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // ================= FAILURE CASE =================
    cout << "\n===== FAILURE CASE =====\n";
    vector<int> fail = {3,2,1,0,4};

    if (canJump(fail)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
