#include <iostream>
#include <vector>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
    string original;
};

bool compareDates(const Date &a, const Date &b) {
    if (a.year != b.year)
        return a.year < b.year;
    if (a.month != b.month)
        return a.month < b.month;
    return a.day < b.day;
}

int partition(vector<Date> &arr, int low, int high) {
    Date pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compareDates(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<Date> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<Date> dates(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dates[i].original = s;
        dates[i].day = stoi(s.substr(0, 2));            //string to int
        dates[i].month = stoi(s.substr(3, 2));
        dates[i].year = stoi(s.substr(6, 4));
    }

    quickSort(dates, 0, n - 1);

    for (int i = 0; i < dates.size(); i++){
        cout << dates[i].original << endl;
    }

    return 0;
}
