#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};


Node* bt_insert(Node* root, int val){
    if(root == nullptr) {
        return new Node(val);
    }
    else {
        if(val < root->data) 
            root->left = bt_insert(root->left, val);
        else 
            root->right = bt_insert(root->right, val);
        return root;
    }
}

int count(Node* cur){
    if(cur == nullptr) return 0;
    return 1 + count(cur->left) + count(cur->right);
}

int search_subtree(Node* cur, int val){
    if(cur == nullptr) return 0;
    else if(cur->data == val) return count(cur);
    else if(val < cur->data) return search_subtree(cur->left, val);
    else return search_subtree(cur->right, val);
}

int main() {
    
    int n, x;
    Node* root = nullptr;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        root = bt_insert(root, x);  // Присваиваем возвращаемое значение
    }
    
    cin >> x;
    
    cout << search_subtree(root, x);
    
    return 0;
}