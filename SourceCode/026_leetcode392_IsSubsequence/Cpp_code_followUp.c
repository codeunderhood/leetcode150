#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class SubsequenceChecker {
public:
    unordered_map<char, vector<int>> pos;

    void preprocess(string t) {
        for (int i = 0; i < t.size(); i++) {
            pos[t[i]].push_back(i);
        }
    }

    bool check(string s) {
        int prev = -1;

        for (char c : s) {
            if (pos.find(c) == pos.end()) return false;

            vector<int> &v = pos[c];

            auto it = upper_bound(v.begin(), v.end(), prev);

            if (it == v.end()) return false;

            prev = *it;
        }

        return true;
    }
};

int main() {
    string t = "ahbgdc";

    SubsequenceChecker sc;
    sc.preprocess(t);

    cout << sc.check("abc") << endl;  // true
    cout << sc.check("axc") << endl;  // false
}
