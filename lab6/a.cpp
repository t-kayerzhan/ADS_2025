#include <iostream>
using namespace std;
int partition(char arr[], int low, int high){
    char pivot = arr[high];
    int i = low - 1;
    for ( int j = low; j < high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;

}
void quick_sort(char arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}
int main(){
    int n;
    cin >> n;
    char arr[n];
    int as = 0, bs = 0;
    char arr_A[n];
    char arr_B[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] == 'a' || arr[i]=='e' || arr[i]=='i' || arr[i] == 'o'|| arr[i]=='u'){
            arr_A[as++] = arr[i];
            
        }else {
            arr_B[bs++]=arr[i];
        }
    }
    quick_sort(arr_A, 0,as-1);
    quick_sort(arr_B, 0, bs-1);
    for(int i = 0; i < as; i++){
        cout << arr_A[i];
    }
    for(int i = 0; i < bs; i++){
        cout << arr_B[i];
    }

}