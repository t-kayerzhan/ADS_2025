#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, s, f, a[101][101];
vector<int> g[101]; //вектор соседей
vector<int> d(101, -1);
queue<int> q;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j]) {
                g[i].push_back(j);
            }
        }
    }
    cin >> s >> f;

    d[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < (int)g[v].size(); i++) {
            int to = g[v][i];
            if (d[to] == -1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }

    cout << d[f];

    return 0;
}
