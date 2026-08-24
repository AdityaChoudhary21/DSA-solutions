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

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

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
Node* insertTail(Node* head,int k){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;

    }
    Node* newNode = new Node (k);
    temp->next=newNode;
    return head;
}

Node* insertHead(Node* head,int k){
    Node* temp = head;
    Node* newNode = new Node (k);
    newNode->next=temp;
    return newNode;
    
}

Node* insertElement(Node* head,int k){
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data > k){
            Node* newNode = new Node (k);
            newNode->next = temp->next;
            temp->next=newNode;
            return head;
        }
        temp = temp->next;

    }
}


int main(){
    vector<int> arr = {19,20,23,25,26};
    Node* head = convertArr2LL(arr);
    head=insertHead(head,18);
    print(head);
    
    head=insertElement(head,21);
    print(head);
    
    head = insertTail(head,27);
    print(head);
    
    return 0;
}
