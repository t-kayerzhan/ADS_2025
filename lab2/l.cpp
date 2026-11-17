#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <limits>
#include <climits>

using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int x): data(x), next(NULL) {}
};

int findMaxSum(int n, Node *head){
    int mx = INT_MIN; int sum = 0;
    for(int i =0; i <n ; i++){
        Node *cur = head;
        head = head->next;
        sum = 0;
        while(cur!=NULL){
            sum+=cur->data;
            cur=cur->next;
            mx=max(mx, sum);
        }
    }
    return mx;
}
int main(){
    int n;
    cin >> n;
    Node *head, *tail ;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        Node *cur = new Node(x);
        if(i==0){head = tail = cur;}
        else {
            tail->next=cur;
            tail = cur;
        }

    }
    cout << findMaxSum(n, head) << endl;
}