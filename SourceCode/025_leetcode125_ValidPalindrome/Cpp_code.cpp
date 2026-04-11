#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {

            // skip non-alphanumeric
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            // compare ignoring case
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};

/* Test */
int main() {
    Solution s;

    string str = "race a car";

    if (s.isPalindrome(str))
        cout << "True";
    else
        cout << "False";

    return 0;
}
