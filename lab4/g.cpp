#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }
    if(val < root->val) root->left = insert(root->left, val);
    else if(val > root->val) root->right = insert(root->right, val);
    return root;
}

int diameter = 0;

int depth(Node* root) {
    if(root == NULL) return 0;
    int L = depth(root->left);
    int R = depth(root->right);
    diameter = max(diameter, L + R);
    return 1 + max(L, R);
}

int main() {
    int n, x;
    cin >> n;

    Node* root = NULL;
    for(int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    depth(root);
    cout << diameter + 1 << "\n";

    return 0;
}