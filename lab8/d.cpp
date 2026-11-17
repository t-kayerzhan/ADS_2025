#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

const long long MOD = 1000000007;
const long long PW = 31;

vector<long long> prefix_hash(const string &s) {
    int n = s.size();
    vector<long long> h(n + 5, 0), p(n + 5, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * PW + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = (p[i] * PW) % MOD;
    }
    return h;
}

long long get_hash(const vector<long long> &h, const vector<long long> &p, int l, int r) {
    long long res = (h[r] - h[l] * p[r - l]) % MOD;
    if (res < 0) res += MOD;
    return res;
}

string s[155], long_str;
long long mx, str_cnt[155];

void solve(int n) {
    mx = INT_MIN;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    cin >> long_str;

    vector<long long> h = prefix_hash(long_str);
    vector<long long> p(long_str.size() + 1, 1);

    for (int i = 1; i <= long_str.size(); i++) {
        p[i] = (p[i - 1] * PW) % MOD;
    }

    for (int i = 1; i <= n; i++) {
        long long hash_s = 0, cnt = 0;
        for (int j = 0; j < s[i].size(); j++) {
            hash_s = (hash_s * PW + (s[i][j] - 'a' + 1)) % MOD;
        }
        for (int j = 0; j + s[i].size() <= long_str.size(); j++) {
            long long substr_hash = get_hash(h, p, j, j + s[i].size());
            if (substr_hash == hash_s) cnt++;
        }
        if (cnt > mx) mx = cnt;
        str_cnt[i] = cnt;
    }

    cout << mx << '\n';
    for (int i = 1; i <= n; i++) {
        if (str_cnt[i] == mx) cout << s[i] << '\n';
    }
}

int main() {
    while (true) {
        int tt;
        cin >> tt;
        if (tt == 0) break;
        solve(tt);
    }
    return 0;
}
