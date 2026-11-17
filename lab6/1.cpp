#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr,int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j < high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}
void quick_sort(vector<int>& arr,int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}
int my_abs(int x){
    if(x<0) return -x;
    else return x;
}
int main(){
   
    int n,x;
    cin >> n;
    vector<int> vc(n);
    for(int i = 0; i <n; i++){
        cin >> vc[i];
    }
    quick_sort(vc, 0, vc.size()-1);
    int min_diff= my_abs(vc[1]- vc[0]);
    for(int i = 0; i < n; i++){
        if(my_abs(vc[i+1]-vc[i])<min_diff){
            min_diff = my_abs(vc[i+1]-vc[i]);
        }

    }
    for(int i = 0; i < n; i++){
        if (my_abs(vc[i+1]-vc[i])==min_diff){
            cout << vc[i] << " " << vc[i+1]<< " ";
        }
    }
}