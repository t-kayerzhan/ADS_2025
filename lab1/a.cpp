#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        queue<int> q;
        for (int i = 1; i <= n; i++) q.push(i);
        vector<int> order;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int x = q.front();
                q.pop();  // delete first element 
                q.push(x); //add to the end
            }
            order.push_back(q.front());
            q.pop();
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            result[order[i] - 1] = i + 1;
        }

        for (int i = 0; i < n; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}