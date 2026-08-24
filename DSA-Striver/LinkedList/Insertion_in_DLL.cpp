#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1,Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
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
    Node* prev = head;
    for(int i =1; i<arr.size(); i++){
        Node* temp = new Node (arr[i],nullptr, prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

Node* insertTail(Node* head,int k){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = new Node (k, nullptr, temp);
    temp->next=newNode;
    return head;
}

Node* insertHead(Node* head,int k){
    Node* temp = head;
    Node* newNode = new Node (k, temp, nullptr);
    newNode->next=temp;
    return newNode;
    
}

Node* insertElement(Node* head,int k){
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data > k){
            Node* forw = temp->next;
            Node* newNode = new Node (k, forw, temp);
            temp->next=newNode;
            forw->back=newNode;
            return head;
        }
        temp = temp->next;

    }
}

int main(){
    vector<int> arr = {29,30,33,35,36};
    Node* head = convertArr2LL(arr);
    head=insertHead(head,28);
    print(head);
    
    head=insertElement(head,31);
    print(head);
    
    head = insertTail(head,37);
    print(head);
    
    return 0;
}
