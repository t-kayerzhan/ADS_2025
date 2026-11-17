#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s1;
    cin >> s1;

    string s2;
    cin >> s2;
    for(int i = 0;  i < s1.size(); i++){
        if (s1[i] == '#'){
            s1.erase(i-1, 2);
            i -= 2;
        }
    
    }
    for(int i = 0;  i < s2.size(); i++){
        if (s2[i] == '#'){
            s2.erase(i-1, 2);
            i -= 2;
        }
    
    }
    if (s1==s2){
        cout << "YES";
    }else{
        cout << "NO";
    }

}