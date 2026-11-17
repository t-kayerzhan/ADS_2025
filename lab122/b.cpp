#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

long long n, m, s, a, b, f;
const int INF = 1000000000;
vector<pair<int, int>> g[100005];

void dijkstra(int s, vector<long long> &d) {
    d.assign(n, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [dist_v, v] = pq.top();
        pq.pop();
        if (dist_v != d[v]) continue;
        for (int i = 0; i < g[v].size(); i++){
            pair<int,int> edge = g[v][i];
            int to = edge.first;
            int len = edge.second;
            if (d[to] > d[v] + len) {
                d[to] = d[v] + len;
                pq.push({d[to], to});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1, l, r, w; i <= m; i++) {
        cin >> l >> r >> w;
        g[--l].push_back({--r, w});
        g[r].push_back({l, w});
    }
    cin >> s >> a >> b >> f;
    s--, a--, b--, f--;
    vector<long long> d1, d2, d3;
    dijkstra(s, d1);
    dijkstra(a, d2);
    dijkstra(b, d3);
    if (d1[a] == INF || d2[b] == INF || d3[f] == INF)
        cout << -1;
    else
        cout << min(d1[a] + d2[b] + d3[f], d1[b] + d3[a] + d2[f]);
    return 0;
}