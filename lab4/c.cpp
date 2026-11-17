#include <iostream>
#include <vector>
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

vector<int> get_subtree_elements(Node* cur){
    vector<int> result;
    if(cur == nullptr) return result;
    
    result.push_back(cur->data);
    vector<int> left_elements = get_subtree_elements(cur->left);
    vector<int> right_elements = get_subtree_elements(cur->right);
    
    result.insert(result.end(), left_elements.begin(), left_elements.end());
    result.insert(result.end(), right_elements.begin(), right_elements.end());
    
    return result;
}

vector<int> search_subtree(Node* cur, int val){
    if(cur == nullptr) return vector<int>();
    else if(cur->data == val) return get_subtree_elements(cur);
    else if(val < cur->data) return search_subtree(cur->left, val);
    else return search_subtree(cur->right, val);
}

int main() {
    
    int n, x;
    Node* root = nullptr;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        root = bt_insert(root, x);
    }
    
    cin >> x;
    
    vector<int> subtree_elements = search_subtree(root, x);
    

    for(int i = 0; i < subtree_elements.size(); i++) {
        cout << subtree_elements[i];
        if(i < subtree_elements.size() - 1) {
            cout << ' ';
        }
    }
    
    return 0;
}