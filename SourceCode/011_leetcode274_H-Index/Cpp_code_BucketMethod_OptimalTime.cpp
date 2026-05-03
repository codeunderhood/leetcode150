#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> count(n + 1, 0);

    // Build frequency buckets
    for (int c : citations) {
        if (c >= n)
            count[n]++;
        else
            count[c]++;
    }

    // Accumulate from right to left
    int total = 0;
    for (int i = n; i >= 0; i--) {
        total += count[i];
        if (total >= i)
            return i;
    }

    return 0;
}

int main() {
    vector<int> citations = {3, 0, 6, 1, 5};

    cout << "H-Index: " << hIndex(citations) << endl;
    return 0;
}
