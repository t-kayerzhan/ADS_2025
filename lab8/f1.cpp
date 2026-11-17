#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

long long MOD = 9007199254740881;
long long PW = 31;

long long getHash(char s)
{
    long long hash = 0;
    long long curPW = 1;

    long long curHash = (s - 'a' + 1) * curPW % MOD;
    hash = (hash + curHash) % MOD;
    curPW = (curPW * PW) % MOD;

    return hash;
}
int main()
{
    string s;
    cin >> s;
    long long cnt = 0;
    unordered_map<unsigned long long, unsigned long long> mp;
    for (int i = 0; i < s.size(); i++)
    {
        long long hash = 0;
        for (int j = i; j < s.size(); j++)
        {
            hash = (hash * 26 + s[j]) % MOD;
            if (mp.find(hash) == mp.end())
            {
                cnt++;
            }
            mp[hash] = 1;
        }
    }
    cout << cnt;
}