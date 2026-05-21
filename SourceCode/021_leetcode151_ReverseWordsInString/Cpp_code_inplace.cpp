#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string s) {

    int n = s.size();

    // STEP 1: Reverse whole string
    reverse(s.begin(), s.end());

    int start = 0;

    // STEP 2: Reverse each word
    for (int end = 0; end <= n; end++) {

        if (end == n || s[end] == ' ') {

            reverse(s.begin() + start, s.begin() + end);

            start = end + 1;
        }
    }

    // STEP 3: Remove extra spaces
    string result = "";
    int i = 0;

    while (i < n) {

        while (i < n && s[i] == ' ')
            i++;

        if (i > 0 && i < n && !result.empty())
            result += ' ';

        while (i < n && s[i] != ' ') {
            result += s[i];
            i++;
        }
    }

    return result;
}

int main() {

    string s = "  the   sky is blue  ";

    cout << reverseWords(s);

    return 0;
}
