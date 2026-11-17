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
    int n, cnt1=0, cnt2 = 0;
    cin >> n;
    for(int i = 2; i <= 100000; i++){
        if(isPrime(i)){
            cnt1++;
            if(isPrime(cnt1)){
                cnt2++;
                if (cnt2 == n){
                    cout << i;

            }
         }
       } 
    }
}