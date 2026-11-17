#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    int a[1000][1000]; 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    const int INF = 1000000000;

    int dist[1000];   
    bool used[1000];  

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        used[i] = false;
    }

    dist[0] = 0;
    long long total = 0;

    for (int it = 0; it < n; it++) {
        int v = -1;

        for (int i = 0; i < n; i++) {
            if (!used[i] && (v == -1 || dist[i] < dist[v]))
                v = i;
        }

        used[v] = true;
        total += dist[v];

        for (int u = 0; u < n; u++) {
            if (!used[u] && a[v][u] < dist[u]) {
                dist[u] = a[v][u];
            }
        }
    }

    cout << total;
    return 0;
}
