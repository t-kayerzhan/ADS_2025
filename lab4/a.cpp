#include <iostream>
#include <string>
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

bool check(string s, Node* node){
    Node* cur = node;
    for(int i = 0; i < s.size(); i++){
        if(cur == nullptr) return false;
        else if(s[i] == 'L') cur = cur->left;
        else cur = cur->right;
    }
    if(cur != nullptr) return true;
    else return false;
}

int main() {
    
    int n, m, x;
    string s;
    Node* root = nullptr;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> x;
        root = bt_insert(root, x);  
    }
    
    for(int i = 1; i <= m; i++){
        cin >> s;
        if(check(s, root)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}