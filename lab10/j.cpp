#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
vector<int> g[100005];
int sons[100005];
bool used[100005];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);  
        sons[l]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            queue<int> q;
            q.push(i);
            used[i] = true;
            ans++;

            while (!q.empty()) {
                int v = q.front();
                q.pop();

                for (int j = 0; j < (int)g[v].size(); j++) {
                    int to = g[v][j];
                    if (!used[to]) {
                        if (sons[v] < sons[to]) ans++;
                        used[to] = true;
                        q.push(to);
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}
