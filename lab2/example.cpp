#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int x): data(x), next(NULL){}
};

int main(){
    int n,k, pos ,cnt = 0, mn = INT_MAX, x;
    cin >> n;
    Node *head = NULL, *tail = NULL;
    for(int i = 0; i < n; i ++){
        cin >> x;
        Node *node = new Node(x);
        if(head = NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }

    }
    Node *cur = head;
    while(cur!=NULL){
        if(abs(cur->data-k)<mn){
            mn=abs(cur->data - k);
            pos= cnt;
        }
        cur=cur->next;
        cnt++;
    }

}