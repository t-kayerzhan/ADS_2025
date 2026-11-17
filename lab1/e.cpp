#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<int> boris, nursik;
    
    // Читаем карты Бориса
    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        boris.push(card);
    }
    
    // Читаем карты Нурсика
    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        nursik.push(card);
    }
    
    int moves = 0;
    
    while (!boris.empty() && !nursik.empty() && moves < 1000000) {
        moves++;
        
        int b_card = boris.front();
        int n_card = nursik.front();
        boris.pop();
        nursik.pop();
        
        // Проверяем специальное правило: 0 побеждает 9
        if (b_card == 0 && n_card == 9) {
            // Борис выигрывает
            boris.push(b_card);
            boris.push(n_card);
        } else if (b_card == 9 && n_card == 0) {
            // Нурсик выигрывает
            nursik.push(b_card);
            nursik.push(n_card);
        }
        // Обычное сравнение
        else if (b_card > n_card) {
            // Борис выигрывает
            boris.push(b_card);
            boris.push(n_card);
        } else {
            // Нурсик выигрывает
            nursik.push(b_card);
            nursik.push(n_card);
        }
    }
    
    if (moves >= 1000000) {
        cout << "blin nichya";
    } else if (boris.empty()) {
        cout << "Nursik " << moves;
    } else {
        cout << "Boris " << moves;
    }
    
    return 0;
}