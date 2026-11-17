#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int myAbs(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector< int> > matrix(n, vector<int> (m));
    for(int i = 0; i <n;i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    for(int j = 0; j < m; j++){
        vector <int> column;
        for(int i = 0; i < n; i++){
            column.push_back(matrix[i][j]);
            
        }
        quickSort(column, 0, column.size()-1);
        for(int i = 0; i < n; i++){
            matrix[i][j] = column[i];
        }
    }
     for(int i = 0; i <n;i++){
        for(int j = 0; j < m; j++){
            cout <<  matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
