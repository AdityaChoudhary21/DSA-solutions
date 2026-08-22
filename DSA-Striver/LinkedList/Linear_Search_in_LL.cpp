#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover= temp;
    }
    return head;
}
int searchIfPresent(Node* head, int x){
    Node* temp = head;
    while(temp){
        if(temp->data == x) return 1;
        temp = temp->next;
    }
    return 0;
}


int main(){
    vector<int> arr = {19,20,23,25,26};
    Node* head = convertArr2LL(arr);
    cout<<searchIfPresent(head,23)<<endl;
    
    return 0;
}
