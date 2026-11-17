#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
using namespace std;

int n, a, b, c;
vector<int> graph[1005];
int lvl[1005], mx = INT_MIN;

int main() {
    
    cin >> n;
    
    for(int i = 1; i < n; i++){
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    memset(lvl, -1, sizeof(lvl));
    lvl[1] = 0;
    queue<int> q;
    map<int, int> mp;
    q.push(1);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int to = graph[u][i];
            if(lvl[to] == -1){
                q.push(to);
                lvl[to] = lvl[u] + 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        mp[lvl[i]]++; //Главное — чтобы lvl[i] у каждой вершины было правильное.
        if(mp[lvl[i]] > mx) mx = mp[lvl[i]];
    }
    
    cout << mx;
    return 0;
}