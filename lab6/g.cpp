#include <iostream>
using namespace std;

struct Pair {
    char oldname[30];
    char newname[30];
};

int strCompare(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0') return 0;
    if (a[i] == '\0') return -1;
    return 1;
}

void strCopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int partition(Pair arr[], int low, int high) {
    char pivot[30];
    strCopy(pivot, arr[high].oldname);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strCompare(arr[j].oldname, pivot) < 0) {
            i++;
            Pair temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Pair temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void QuickSort(Pair arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    Pair pairs[1005];
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].oldname >> pairs[i].newname;
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && pairs[i].oldname[0] != '\0' && pairs[j].oldname[0] != '\0') {
                    if (strCompare(pairs[i].newname, pairs[j].oldname) == 0) {
                        strCopy(pairs[i].newname, pairs[j].newname);
                        pairs[j].oldname[0] = '\0'; 
                        changed = true;
                    }
                }
            }
        }
    }


    int count = 0;
    for (int i = 0; i < n; i++) {
        if (pairs[i].oldname[0] != '\0') count++;
    }

    cout << count << "\n";

    QuickSort(pairs, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (pairs[i].oldname[0] != '\0')
            cout << pairs[i].oldname << " " << pairs[i].newname << "\n";
    }

    return 0;
}