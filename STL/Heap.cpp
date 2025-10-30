#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 15, 30, 40};

    make_heap(v.begin(), v.end());   // build max-heap
    cout << "Max element: " << v.front() << "\n";

    v.push_back(50);
    push_heap(v.begin(), v.end());   // insert new element
    cout << "New Max: " << v.front() << "\n";

    pop_heap(v.begin(), v.end());    // remove max
    cout << "Popped Max: " << v.back() << "\n";
    v.pop_back();

    sort_heap(v.begin(), v.end());   // sort ascending
    cout << "Sorted: ";
    for (int x : v) cout << x << " ";
    cout << "\n";
}
