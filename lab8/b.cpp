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
    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    int n = s1.size();
    int m = t.size();

    vector<long long> h1 = prefix_hash(s1);
    vector<long long> h2 = prefix_hash(s2);

    vector<long long> p(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i - 1] * PW) % MOD;
    }

    long long hash_t = 0;
    for (int i = 0; i < t.size(); i++) {
    hash_t = (hash_t * PW + (t[i] - 'a' + 1)) % MOD;
}

    int count = 0;
    for (int i = 0; i + m <= n; i++) {
        long long h_s1 = get_hash(h1, p, i, i + m);
        long long h_s2 = get_hash(h2, p, i, i + m);
        if (h_s1 == hash_t && h_s2 == hash_t) {
            count++;
        }
    }

    cout << count << "\n";
}

int main() {
    solve();
    return 0;
}
