#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct person {
    string surname;
    string name;
    double gpa;
};

bool cmp(person a, person b) {
    if (a.gpa != b.gpa) return a.gpa < b.gpa;
    if (a.surname != b.surname) return a.surname < b.surname;
    return a.name < b.name;
}

int partition(vector<person>& arr, int low, int high) {
    person pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (cmp(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<person>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<person> p(n);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> p[i].surname >> p[i].name >> m;
        double sum = 0;
        int credits = 0;

        for (int j = 0; j < m; j++) {
            string grade;
            int credit;
            cin >> grade >> credit;
            double val = 0;
            if (grade == "A+") val = 4.0;
            else if (grade == "A") val = 3.75;
            else if (grade == "B+") val = 3.5;
            else if (grade == "B") val = 3.0;
            else if (grade == "C+") val = 2.5;
            else if (grade == "C") val = 2.0;
            else if (grade == "D+") val = 1.5;
            else if (grade == "D") val = 1.0;
            else val = 0;

            sum += val * credit;
            credits += credit;
        }

        p[i].gpa = sum / credits;
    }

    quickSort(p, 0, n - 1);

    cout << fixed << setprecision(3);
    for (int i = 0; i < p.size(); i++){

        cout << p[i].surname << " " << p[i].name << " " << p[i].gpa << endl;
    }
        
}
