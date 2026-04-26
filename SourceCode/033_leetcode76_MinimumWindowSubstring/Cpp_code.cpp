#include <iostream>
#include <vector>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    vector<int> need(128, 0), window(128, 0);

    // Step 1: frequency of t
    for (char c : t) {
        need[c]++;
    }

    int required = 0;
    for (int i = 0; i < 128; i++) {
        if (need[i] > 0) required++;
    }

    int l = 0, r = 0;
    int formed = 0;

    int minLen = INT_MAX;
    int start = 0;

    while (r < s.size()) {
        char c = s[r];
        window[c]++;

        if (need[c] > 0 && window[c] == need[c]) {
            formed++;
        }

        // shrink window
        while (l <= r && formed == required) {

            // update best answer
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }

            char leftChar = s[l];
            window[leftChar]--;

            if (need[leftChar] > 0 &&
                window[leftChar] < need[leftChar]) {
                formed--;
            }

            l++;
        }

        r++;
    }

    if (minLen == INT_MAX) return "";

    return s.substr(start, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s, t) << endl;

    return 0;
}
