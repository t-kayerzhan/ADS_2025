#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> d(40005, -1);
vector<int> path(40005);
queue<int> q;

int main() {
    int s, f;
    cin >> s >> f;

    if (s == f) {
        cout << 0;
        return 0;
    } 
    else if (s > f) {
        cout << s - f << '\n';
        for (int i = s - 1; i >= f; i--) {
            cout << i << ' ';
        }
        return 0;
    }

    q.push(s);
    d[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        // v * 2
        if (v * 2 <= 40000 && d[v * 2] == -1) {
            d[v * 2] = d[v] + 1;
            path[v * 2] = v;
            q.push(v * 2);
        }

        // v - 1
        if (v - 1 > 0 && d[v - 1] == -1) {
            d[v - 1] = d[v] + 1;
            path[v - 1] = v;
            q.push(v - 1);
        }

        if (d[f] != -1) break;
    }

    vector<int> ans;
    int cur = f;
    
    while (cur != -1 && cur != s) {
        ans.push_back(cur);
        cur = path[cur];
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
