#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Edge {
    long long to; //Номер вершины
    long long w;// Вес ребра
};

int main() {
    long long n, m, x, y, a, b, c;

    cin >> n >> m;
    cin >> x >> y;

    vector<vector<Edge> > g(n + 1);

    for (int i = 0; i < m; i++) {
        string type;
        long long cost;

        cin >> type >> a >> b >> c;

        if (type == "big")
            cost = 1ll * x * c;
        else if (type == "small")
            cost = 1ll * y * c;
        else
            cost = 1ll * min(x, y) * c;

        Edge e1; e1.to = b; e1.w = cost; // from a to b
        Edge e2; e2.to = a; e2.w = cost;

        g[a].push_back(e1);
        g[b].push_back(e2);
    }
//MST 
    vector<bool> used(n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;

    pq.push(make_pair(0, 1)); // first - cost, second - node начинаем с вершины 1
    long long total = 0;

    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();

        long long w = top.first;
        int v = top.second;

        if (used[v]) continue;
        used[v] = true;
        total += w; //+стоим.  ребра

        for (int i = 0; i < (int)g[v].size(); i++) {
            Edge e = g[v][i];
            if (!used[e.to]) {
                pq.push(make_pair(e.w, e.to));
            }
        }
    }

    cout << total;
    return 0;
}
