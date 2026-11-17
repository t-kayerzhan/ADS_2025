#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    if(n > 0) mergeSort(a, 0, n - 1);
    if(m > 0) mergeSort(b, 0, m - 1);

    vector<int> common;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            common.push_back(a[i]);
            i++;
            j++;
        } else if (a[i] < b[j]) i++;
        else j++;
    }

    for (int k = 0; k < common.size(); k++) {
        if (k) cout << " ";
        cout << common[k];
    }
    if(!common.empty()) cout << endl;

    return 0;
}
