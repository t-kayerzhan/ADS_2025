#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int n, m, a[1001][1001], cnt=0, check=0;
int d[1001][1001], ans = 0;
int main(){
    queue<pair<int,int> > q;
    cin >> n >> m;
    for(int i = 0; i <=n; i++){
        for(int j = 0; j <=m; j++){
            d[i][j]=INT_MAX;
        }
    }
    for(int i = 1; i<=m; i++){
        for(int j = 1; j <=m; j++){
            cin >> a[i][j];
            if(a[i][j]==2){
                q.push(make_pair(i,j));
                d[i][j]=0;
            }
            if(a[i][j]==0) cnt++;
        }
    }
    int dirs[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
    while(!q.empty()){
        pair<int,int> 
    }
}
