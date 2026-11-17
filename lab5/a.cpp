#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap; // min-heap

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        minHeap.push(x);
    }

    long long total_cost = 0;

    // Keep merging until one array remains
    while (minHeap.size() > 1) {
        long long a = minHeap.top(); 
        minHeap.pop();
        long long b = minHeap.top();
        minHeap.pop();

        long long merged = a + b;
        total_cost += merged;

        minHeap.push(merged);
    }

    cout << total_cost << endl;
    return 0;
}
