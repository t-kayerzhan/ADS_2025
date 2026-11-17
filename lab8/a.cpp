#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

vector<string> v;
unordered_set<string> st;

string hashing(const string &s) {
    long long h = 0, p = 1;
    for (int i = 0; i < s.size(); i++) {
        h = (h + ((s[i] - 47) * p) % MOD) % MOD;
        p = (p * 11) % MOD;
    }
    return to_string(h);
}

void solve() {
    int n;
    string s;

    cin >> n;
    for (int i = 1; i <= n * 2; i++) {
        cin >> s;
        v.push_back(s);
        st.insert(s);
    }

    int count = 0;

    for (int i = 0; i < v.size(); i++) {
        if (count == n) break;

        string hs = hashing(v[i]);
        if (st.find(hs) != st.end()) { 
            /*1️⃣ Если элемент нашёлся st.find(x) → итератор на этот элемент.
            2️⃣ Если элемент не найден st.find(x) → итератор на st.end()*/
            cout << "Hash of string \"" << v[i] << "\" is " << hs << "\n";
            count++;
        }
    }
}

int main() {
    solve();
    return 0;
}
