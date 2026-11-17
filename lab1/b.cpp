#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        int answer = -1;
        
        // Идем СПРАВА НАЛЕВО от текущего элемента к началу
        // Ищем ПЕРВОЕ меньшее число (самое близкое к текущему)
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] <= arr[i]) {
                answer = arr[j];
                break;
            }
        }
        
        cout << answer << " ";
    }
    
    return 0;
}