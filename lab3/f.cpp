#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;

int main() {
    
    int n, m, x;
    int a[N];
    long long pref[N]; 
    
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    pref[0] = 0;
    for(int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
    
    cin >> m;
    
    for(int i = 0; i < m; i++){
        cin >> x;
        int l = 0, r = n;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(a[mid] > x) r = mid;
            else l = mid;
        }
        
        // Проверка на случай, если все элементы > x
        if(a[l] <= x) {
            cout << l + 1 << " " << pref[l + 1] << "\n";
        } else {
            cout << "0 0\n";
        }
    }
    
    return 0;
}