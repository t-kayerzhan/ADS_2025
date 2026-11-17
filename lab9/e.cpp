#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> computeLPS(const string &pattern){
    int n = pattern.size();
    vector<int> lps(n,0);
    int len = 0;
    int i = 1;
    while(i < n){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        long long k;
        cin >> s >> k;

        vector<int> lps = computeLPS(s);
        int n = s.size();
        int p = lps[lps.size()-1];

        long long res = n + (k - 1) * (n - p);
        /*
        Первая копия строки занимает n символов
        Каждый следующий повтор добавляет только (n - p) символов, потому что p символов перекрываются
        Всего повторов: k → первый уже учтён, оставшиеся (k-1)
        */
        cout << res << '\n';
    }
    return 0;
}