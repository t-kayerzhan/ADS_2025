#include <iostream>
#include <vector>
using namespace std;

int n, qu, x;
vector<int> g[5005];

int main() {
    cin >> n >> qu;

    // читаем матрицу смежности
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int v;
            cin >> v;
            if (v == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for (int i = 1; i <= qu; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        bool ok1 = false, ok2 = false, ok3 = false;

        // проверяем связи x - y и x - z
        for (int j = 0; j < (int)g[x].size(); j++) {
            int to = g[x][j];
            if (to == y) ok1 = true;
            if (to == z) ok2 = true;
        }

        // проверяем связь y - z
        for (int j = 0; j < (int)g[y].size(); j++) {
            int to = g[y][j];
            if (to == z) ok3 = true;
        }

        if (ok1 && ok2 && ok3) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
