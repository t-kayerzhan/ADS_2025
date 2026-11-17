#include <iostream>
#include <vector>
using namespace std;
bool compareRows(const vector<int>& a, const vector<int>& b) {
    int sumA = 0, sumB = 0;
    for (int x : a) sumA += x;
    for (int x : b) sumB += x;
    
    if (sumA != sumB) return sumA > sumB; // убывание по сумме
    // если суммы равны, лексикографическое сравнение
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false; // строки равны
}

void merge(vector<vector<int>>& arr, int l, int m, int r) {
    vector<vector<int>> L(arr.begin() + l, arr.begin() + m + 1);
    vector<vector<int>> R(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) {
        if (compareRows(L[i], R[j])) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<vector<int>>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    mergeSort(matrix, 0, n - 1);

    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cout << matrix[i][j];
        cout << " "; // пробел после каждого числа, даже последнего
    }
    cout << "\n";
}

    return 0;
}
