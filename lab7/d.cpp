#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string surname;
    string name;
    double gpa;
};

void merge(vector<Student>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<Student> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].gpa != R[j].gpa) {
            if (L[i].gpa < R[j].gpa) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        } else if (L[i].surname != R[j].surname) {
            if (L[i].surname < R[j].surname) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        } else {
            if (L[i].name < R[j].name) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<Student>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        string surname, name;
        int m;
        cin >> surname >> name >> m;
        students[i].surname = surname;
        students[i].name = name;

        double totalGPA = 0;
        int totalCredits = 0;
        for (int j = 0; j < m; j++) {
            string grade;
            int credit;
            cin >> grade >> credit;
            double g = 0;
            if (grade == "A+") g = 4.0;
            else if (grade == "A") g = 3.75;
            else if (grade == "B+") g = 3.5;
            else if (grade == "B") g = 3.0;
            else if (grade == "C+") g = 2.5;
            else if (grade == "C") g = 2.0;
            else if (grade == "D+") g = 1.5;
            else if (grade == "D") g = 1.0;
            else if (grade == "F") g = 0.0;

            totalGPA += g * credit;
            totalCredits += credit;
        }
        students[i].gpa = totalGPA / totalCredits;
    }
    mergeSort(students, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << students[i].surname << " " << students[i].name << " ";
        cout << fixed << setprecision(3) << students[i].gpa << endl;
    }
    return 0;
}
