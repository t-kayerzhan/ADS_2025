#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
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

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    vector<bool> used(n, false);
    vector<int> result;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        cin >> b[i];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
        if (!used[j] && a[j] == b[i]) {
            result.push_back(b[i]);
            used[j] = true;
            break;
        }
    }
}

    quickSort(result, 0, result.size() - 1);

    for (int i = 0; i < result.size(); i++)
       {cout << result[i] << " ";}

    return 0;
}
