#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string reverseWords(string s) {

    vector<string> words;
    string word;

    stringstream ss(s);

    // Extract words automatically skipping spaces
    while (ss >> word) {
        words.push_back(word);
    }

    string result = "";

    // Add words in reverse order
    for (int i = words.size() - 1; i >= 0; i--) {

        result += words[i];

        if (i != 0)
            result += " ";
    }

    return result;
}

int main() {

    string s = "  hello   world  ";

    cout << reverseWords(s);

    return 0;
}
