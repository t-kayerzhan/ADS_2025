#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> computeLPS(const string &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len])
            lps[i++] = ++len;
        else if (len != 0)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    return lps;
}

int main() {
    string p;
    int n;
    cin >> p >> n;

    vector<string> cities(n);
    for (int i = 0; i < n; ++i)
        cin >> cities[i];

    string p_lower = p;
    transform(p_lower.begin(), p_lower.end(), p_lower.begin(), ::tolower);
/*
for (int i = 0; i < c_lower.size(); i++)
    c_lower[i] = tolower(c_lower[i]);

*/
    int mx = 0;
    vector<pair<string, int>> match;

    for (int i = 0; i < cities.size(); i++) {
        string c_lower = cities[i];
        transform(c_lower.begin(), c_lower.end(), c_lower.begin(), ::tolower);

        string combined = c_lower + "#" + p_lower;
        vector<int> lps = computeLPS(combined);
        int m = lps[lps.size() - 1];

        match.push_back({cities[i], m});
        mx = max(mx, m);
    }

    vector<string> res;
    for (int i = 0; i < match.size(); i++) {
        string &c = match[i].first;
        int &m = match[i].second;

        if (m == mx && m > 0)
            res.push_back(c);
    }

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << "\n";

    return 0;
}
