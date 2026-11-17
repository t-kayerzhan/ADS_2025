#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {  // only up to √n
        if (n % i == 0) return false;
    }
    return true;
}
int main(){
    int n, cnt=0;
    cin >> n;
    for(int i = 2; i <= 100000; i++){
        if(isPrime(i)){
            cnt++;
        if (cnt == n){
            cout << i;

        }}
        
    }
}