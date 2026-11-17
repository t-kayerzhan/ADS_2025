#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, l, r;
vector<int> g[100005];
bool used[100005];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cin >> l >> r;

    queue<int> q;
    q.push(l);
    used[l] = true;   // важно!

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < (int)g[v].size(); i++) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push(to);
            }
        }
    }

    if (used[r]) cout << "YES";
    else cout << "NO";

    return 0;
}
