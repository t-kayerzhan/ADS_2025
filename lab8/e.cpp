#include <iostream>
#include <string>

using namespace std;

long long n, h[55], power[55], a[55];

void solve() {
    cin >> n;

    power[0] = 1;
    for (int i = 1; i <= 51; i++) {
        power[i] = power[i - 1] * 2;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        long long cur;
        if (i > 0) cur = (a[i] - a[i - 1]) / power[i] + 97;
        else cur = a[i] + 97;
        cout << char(cur);
    }
    cout << '\n';
}

int main() {
    solve();
}
