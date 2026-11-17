#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(!st.empty() && st.top() == c){
            st.pop();
        }else {
            st.push(c);
        }
    }
    string result;
    while(!st.empty()){
        result = st.top() + result;
        st.pop(); // delete the last(top) element
    }
    if (result.empty()){
        cout << "YES";
    }else {
        cout << "NO";
    }
}