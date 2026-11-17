#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    long long u, v, w;
    Edge(long long _u, long long _v, long long _w) : u(_u), v(_v), w(_w) {}
};


const long long INF = 1e18 + 3;

int main() {
    int n;
    cin >> n;

    vector<Edge> edges;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long w;
            cin >> w;
            if (w != 100000) {
                edges.push_back(Edge(i, j, w));


            }
        }
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int x = -1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < edges.size(); ++j) {
            if (dist[edges[j].v] > dist[edges[j].u] + edges[j].w) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
                parent[edges[j].v] = edges[j].u;
                x = edges[j].v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    int y = x;
    for (int i = 0; i < n; ++i) {
        y = parent[y];
    }

    vector<int> cycle;
    int cur = y;
    do {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != y);
    cycle.push_back(y);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    cout << cycle.size() << "\n";
    for (int i = 0; i < cycle.size(); ++i) {
        cout << cycle[i] << " ";
    }
    cout << "\n";

    return 0;
}