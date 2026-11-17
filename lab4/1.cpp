#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *right;
    Node *left;
    Node(int x): data(x), left(nullptr), right(nullptr){}
};
Node* bt_insert(Node* root, int val){
    if(root==nullptr) return new Node(val);
    else{
        if(val<root->data){
            root->left = bt_insert(root->left, val);
        }else {
            root->right=bt_insert(root->right, val);
        }
    }
    return root;
}
int cnt[5005];
int max_lvl=0;

void arbuz_arbuz(Node* root,int lvl ){
    if(root==nullptr) return;
    cnt[lvl]+=root->data;
    arbuz_arbuz(root->left,lvl+1);
    arbuz_arbuz(root->right, lvl+1);
    max_lvl=max(max_lvl, lvl);
}
int main(){
    Node* root = NULL;
    int n,x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        root = bt_insert(root, x);
    }
    arbuz_arbuz(root, 0);
    cout << max_lvl+1<<endl;
    for(int i = 0; i <= max_lvl; i++){
        cout << cnt[i] << ' ';
    }
}