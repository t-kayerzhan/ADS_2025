#include <iostream>
#include <vector>
#include <string>

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

void solve() {
    string s;
    cin >> s;
    string check(s.size(), '0');
    vector<long long> h = prefix_hash(s);
    vector<long long> p(s.size() + 1, 1);
    for (int i = 1; i <= s.size(); i++) {
        p[i] = (p[i - 1] * PW) % MOD;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        long long hash_t = 0;
        for (int j = 0; j < t.size(); j++) {
            hash_t = (hash_t * PW + (t[j] - 'a' + 1)) % MOD;
        }
        for (int j = 0; j + t.size() <= s.size(); j++) {
            long long substr_hash = get_hash(h, p, j, j + t.size());
            if (substr_hash == hash_t) {
                for (int k = j; k < j + t.size(); k++) {
                    check[k] = '1';
                }
            }
        }
    }
    for (int i = 0; i < check.size(); i++) {
        if (check[i] == '0') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    solve();
}
