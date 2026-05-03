#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());

    int n = citations.size();
    int h = 0;

    for (int i = n - 1; i >= 0; i--) {
        int papers = n - i;

        if (citations[i] >= papers) {
            h = papers;
        } else {
            break;
        }
    }

    return h;
}

int main() {
    vector<int> citations = {3, 0, 6, 1, 5};

    cout << "H-Index: " << hIndex(citations) << endl;
}
