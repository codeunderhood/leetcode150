#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    vector<int> arr;
    unordered_map<int,int> mp; // value -> index

public:
    bool insert(int val) {
        if(mp.count(val)) return false;

        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val) {
        if(!mp.count(val)) return false;

        int idx = mp[val];
        int last = arr.back();

        arr[idx] = last;
        mp[last] = idx;

        arr.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }

    void print() {
        cout << "Array: ";
        for(int x : arr) cout << x << " ";
        cout << "\n";
    }
};

int main() {
    srand(time(0));

    RandomizedSet rs;

    cout << rs.insert(10) << endl;
    cout << rs.insert(20) << endl;
    cout << rs.insert(30) << endl;

    rs.print();

    cout << "Random: " << rs.getRandom() << endl;

    cout << rs.remove(20) << endl;

    rs.print();

    cout << "Random: " << rs.getRandom() << endl;

    return 0;
}
