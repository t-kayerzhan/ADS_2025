#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> indeg0;

bool topo_with_remove_to(int remove_to) {
    vector<int> indeg = indeg0;

    if (remove_to != -1) {
        if (indeg[remove_to] != 0) {
            indeg[remove_to]--;
        }
    }

    queue<int> q;

    // добавляем все вершины с нулевой степенью
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0)
            q.push(i);
    }

    int processed = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        processed++;

        for (int j = 0; j < (int)adj[u].size(); j++) {
            int v = adj[u][j];
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    return (processed == n);
}

int main() {
    cin >> n >> m;

    adj.assign(n, vector<int>());
    indeg0.assign(n, 0);

    // читаем граф
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        indeg0[v]++;
    }

    // проверяем начальную топологию
    if (topo_with_remove_to(-1)) {
        cout << "YES\n";
        return 0;
    }

    // пытаемся понизить входящую степень одной вершины
    for (int v = 0; v < n; ++v) {
        if (indeg0[v] == 0) continue;

        if (topo_with_remove_to(v)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
