#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};


Node* insert(Node* root, int val){
    if(root == NULL) {
        return new Node(val);
    }
    else {
        if(val < root->val) 
            root->left = insert(root->left, val);
        else 
            root->right = insert(root->right, val);
        return root;
    }
}

int sum = 0;

void travel(Node* cur){
    if(cur == NULL) return;
    else {
        if(cur->left != NULL && cur->right != NULL) sum++;
        travel(cur->left);
        travel(cur->right);
    }
}

int main() {

    int n, x;
    Node* root = NULL;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        root = insert(root, x);  // Присваиваем результат!
    }
    
    travel(root);
    
    cout << sum;
    
    return 0;
}