#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector <string> vc(n);
    for(int i = 0; i < n; i++){
        cin >> vc[i];}
        
    for(int i = k; i < vc.size(); i++){
        cout << vc[i] << " ";

    }
    for(int i = 0; i < k; i++){
        cout << vc[i] << " ";
    }
    

}
