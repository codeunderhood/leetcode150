#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /*
        STEP 1: BUILD LPS ARRAY
        lps[i] tells:
        → longest prefix which is also suffix in pattern[0..i]
    */
    vector<int> buildLPS(string pat) {

        int m = pat.size();
        vector<int> lps(m, 0);

        int len = 0;  // length of previous match
        int i = 1;    // start from index 1

        // loop builds LPS for each character
        while (i < m) {

            // CASE 1: match → extend prefix-suffix
            if (pat[i] == pat[len]) {
                len++;              // increase match length
                lps[i] = len;      // store result
                i++;               // move forward
            }

            // CASE 2: mismatch
            else {

                // try previous best prefix
                if (len != 0) {
                    len = lps[len - 1]; // fallback using LPS
                }

                // no prefix left
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    /*
        STEP 2: KMP SEARCH
    */
    int strStr(string txt, string pat) {

        int n = txt.size();
        int m = pat.size();

        vector<int> lps = buildLPS(pat);  // preprocess pattern

        int i = 0; // pointer for text
        int j = 0; // pointer for pattern

        // scan full text
        while (i < n) {

            // CASE 1: characters match
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            // CASE 2: full match found
            if (j == m) {
                return i - j;
            }

            // CASE 3: mismatch
            else if (i < n && txt[i] != pat[j]) {

                // if we have partial match, use LPS
                if (j != 0) {
                    j = lps[j - 1];  // jump instead of restart
                }

                // else move text pointer
                else {
                    i++;
                }
            }
        }

        return -1;
    }
};

int main() {

    Solution sol;

    string txt = "ababcabcabababd";
    string pat = "ababd";

    cout << "Index: " << sol.strStr(txt, pat) << endl;

    return 0;
}
