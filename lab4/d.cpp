#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int cnt[5005];


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

int max_lvl = 0;
void arbuz_arbuz(Node* root, int lvl){
    if(root == nullptr) return;
    cnt[lvl] += root->data;
    arbuz_arbuz(root->left, lvl+1);
    arbuz_arbuz(root->right, lvl+1);
    max_lvl = max(max_lvl, lvl);
}

int main() {
    
    int n, x;
    Node* root = NULL;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> x;
        root = bt_insert(root, x);  // Присваиваем результат!
    }
    
    arbuz_arbuz(root, 0);
    
    cout << max_lvl + 1 << '\n';
    
    for(int i = 0; i <= max_lvl; i++) cout << cnt[i] << ' '; 
    
    return 0;
}