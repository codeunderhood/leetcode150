#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100005

int arr[MAX];
int mp[MAX];   // value -> index (assumes values are small positive ints)
int size = 0;

int insert(int val) {
    if(mp[val] != -1)
        return 0;

    arr[size] = val;
    mp[val] = size;
    size++;
    return 1;
}

int removeVal(int val) {
    if(mp[val] == -1)
        return 0;

    int idx = mp[val];
    int last = arr[size - 1];

    arr[idx] = last;
    mp[last] = idx;

    size--;
    mp[val] = -1;

    return 1;
}

int getRandom() {
    int idx = rand() % size;
    return arr[idx];
}

void print() {
    printf("Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // initialize map
    for(int i = 0; i < MAX; i++)
        mp[i] = -1;

    printf("%d\n", insert(10));
    printf("%d\n", insert(20));
    printf("%d\n", insert(30));

    print();

    printf("Random: %d\n", getRandom());

    printf("%d\n", removeVal(20));

    print();

    printf("Random: %d\n", getRandom());

    return 0;
}
