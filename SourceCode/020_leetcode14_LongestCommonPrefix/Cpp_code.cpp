#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {

        // Edge case
        if (strs.empty())
            return "";

        // Traverse characters of first string
        for (int i = 0; i < strs[0].length(); i++) {

            char current = strs[0][i];

            // Compare with all strings
            for (int j = 1; j < strs.size(); j++) {

                // Mismatch OR string ended
                if (i >= strs[j].length() ||
                    strs[j][i] != current) {

                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};

int main() {

    Solution obj;

    vector<string> strs = {"flower", "flow", "flight"};

    cout << obj.longestCommonPrefix(strs);

    return 0;
}
