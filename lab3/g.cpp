#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        pref[i] = pref[i - 1] + a;
    }
    
    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        // Бинарный поиск первого блока, где pref[block] >= x
        int block = lower_bound(pref.begin() + 1, pref.end(), x) - pref.begin();
        cout << block << "\n";
    }
    
    return 0;
}