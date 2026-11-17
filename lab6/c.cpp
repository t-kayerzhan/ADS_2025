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
int myAbs(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}
int main() {
    int n;
    cin >> n ;

    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    quickSort(a, 0, a.size() - 1);
    int min_dif = myAbs(a[1]-a[0]);
    for(int i = 0; i < n-1; i++){
        int dif=myAbs(a[i+1]-a[i]);
        if(dif<min_dif){
            min_dif=dif;
        }
    }
    for (int i = 0; i < n-1; i++){
        if(myAbs(a[i+1]-a[i])==min_dif){
            cout << a[i] << " " << a[i+1] << " ";
        }
    }

    return 0;
}
