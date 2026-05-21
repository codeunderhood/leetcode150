#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {

    int i = s.length() - 1;
    int count = 0;

    // Step 1: Skip trailing spaces
    while(i >= 0 && s[i] == ' ') {
        i--;
    }

    // Step 2: Count last word length
    while(i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
}

int main() {

    string s = "Hello World";

    cout << lengthOfLastWord(s);

    return 0;
}
