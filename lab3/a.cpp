#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int t;
    cin >> t;
    vector <int> query (t);
    for(int i = 0; i < t; i++) cin >> query[i];
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int> > snake (rows, vector<int>(cols));
    map<int, pair<int, int> >coord;
    for(int i = 0; i< rows; i++){
        for(int j = 0; j < cols; j++){
            cin>> snake[i][j];
            coord[snake[i][j]]=  make_pair(i, j);
        }
    }
    for(int i =0 ; i < t; i++){
        if(coord.count(query[i])){
            cout << coord[query[i]].first<< " " << coord[query[i]].second<< endl;
        }else { cout << "-1"<<endl;}
    }
}