#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<long long> pq;
    long long n, x;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
    
    while (pq.size() > 1) {
        long long u = pq.top();
        pq.pop();
        long long v = pq.top();
        pq.pop();
        if(u!=v){
            long long diff;
            if(u>v) {
                diff = u-v;
            }else diff = v - u;
            pq.push(diff);
        }
    }
    
    if (pq.empty())
        cout << 0;
    else
        cout << pq.top();
    
    return 0;
}
