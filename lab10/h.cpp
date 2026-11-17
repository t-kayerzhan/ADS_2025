#include <iostream>
#include <queue>
using namespace std;

int n, m, ans;
char c[101][101];
bool used[101][101];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '1' && !used[i][j]) {
                ans++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                used[i][j] = true;

                while (!q.empty()) {
                    int l = q.front().first;
                    int r = q.front().second;
                    q.pop();

                    // движение вниз
                    if (l + 1 <= n && !used[l + 1][r] && c[l + 1][r] == '1') {
                        q.push(make_pair(l + 1, r));
                        used[l + 1][r] = true;
                    }
                    // движение вверх
                    if (l - 1 >= 1 && !used[l - 1][r] && c[l - 1][r] == '1') {
                        q.push(make_pair(l - 1, r));
                        used[l - 1][r] = true;
                    }
                    // движение вправо
                    if (r + 1 <= m && !used[l][r + 1] && c[l][r + 1] == '1') {
                        q.push(make_pair(l, r + 1));
                        used[l][r + 1] = true;
                    }
                    // движение влево
                    if (r - 1 >= 1 && !used[l][r - 1] && c[l][r - 1] == '1') {
                        q.push(make_pair(l, r - 1));
                        used[l][r - 1] = true;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}
