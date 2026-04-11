#include <iostream>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;

    while (j < t.size()) {
        if (i < s.size() && s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == s.size();
}

int main() {
    string s = "abc";
    string t = "ahbgdc";

    cout << (isSubsequence(s, t) ? "true" : "false");
}
