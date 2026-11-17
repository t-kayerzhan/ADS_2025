#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Вставка элемента
Node* insert(Node* head, int x, int p) {
    Node* newNode = new Node(x);
    if (p == 0) {
        newNode->next = head;
        return newNode;
    }
    
    Node* cur = head;
    for (int i = 0; i < p - 1 && cur; i++) { //просто находит куда вставлять
        cur = cur->next;
    }
    
    if (cur) {
        newNode->next = cur->next; //вставляет
        cur->next = newNode;  // A B(cur), X,  C D
    }
    return head;
}

// Удаление элемента
Node* remove(Node* head, int p) {
    if (!head) return nullptr;
    
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node* cur = head;
    for (int i = 0; i < p - 1 && cur && cur->next; i++) {
        cur = cur->next;
    }
    
    if (cur && cur->next) {
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }
    return head;
}

// Перемещение элемента (простая версия)
Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) return head;
    
    // Находим значение элемента для перемещения
    Node* cur = head;
    for (int i = 0; i < p1 && cur; i++) {
        cur = cur->next;
    }
    if (!cur) return head;
    int value = cur->val;
    
    // Удаляем и вставляем
    head = remove(head, p1);
    return insert(head, value, p2);
}

// Разворот списка
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    
    while (current) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next; // A B C(cur) D (cur2)
    }
    return prev;
}

// Печать списка
void print(Node* head) {
    if (!head) {
        cout << -1 << endl;
        return;
    }
    
    while (head) {
        cout << head->val;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

// Циклический сдвиг влево
Node* cyclic_left(Node* head, int x) {
    if (!head || x == 0) return head;
    
    // Находим длину и хвост
    int length = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }
    
    x = x % length;
    if (x == 0) return head;
    
    // Находим новую голову
    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) {
        newTail = newTail->next;
    }
    
    Node* newHead = newTail->next;
    newTail->next = nullptr;//1 -> 2 -> nullptr    3 -> 4 -> 5 -> nullptr
    tail->next = head;      // tail->next = head — хвост исходного списка (5) теперь указывает на старую голову (1)
    
    return newHead;
}

// Циклический сдвиг вправо
Node* cyclic_right(Node* head, int x) {
    if (!head) return head;
    
    // Находим длину
    int length = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }
    
    return cyclic_left(head, length - (x % length));
}

// Главная функция
int main() {
    Node* head = nullptr;
    int command;
    
    while (cin >> command && command != 0) {
        if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = insert(head, x, p);
        } else if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        } else if (command == 3) {
            print(head);
        } else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        } else if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    

    
    return 0;
}