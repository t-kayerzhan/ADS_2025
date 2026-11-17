#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {

        int l, r;
        cin >> l >> r;
        string sub = "";

        for (int j = l - 1; j < r; ++j)
        {
            sub += s[j];
        }
        int count = 0;

        for (int k = 0; k <= s.length() - sub.length(); ++k)
        {
            bool f = true;
            for (int j = 0; j < sub.length(); ++j)
            {
                if (s[k + j] != sub[j])
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                count++;
            }
        }
        cout << count << endl;
    }
}