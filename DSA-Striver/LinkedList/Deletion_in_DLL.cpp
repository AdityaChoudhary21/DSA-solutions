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

Node* ConvertArrtoDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
Node* deletehead(Node* head){
    Node* temp = head;
    head=head->next;
    temp->next=nullptr;
    head->back=nullptr;
    free(temp);
    return head;

}
Node* deleteTail(Node* head){
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* prev = temp->back;
    prev->next=nullptr;
    temp->back=nullptr;
    free(temp);
    return head;
}
Node* deleteElement(Node* head, int k){
    Node* prev = NULL;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==k){
            Node* forw = temp->next;
            prev->next=forw;
            forw->back=prev;
            temp->next=nullptr;
            temp->back=nullptr;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;

}
int main(){
    vector<int> arr = {29, 30 , 33 , 35, 36};
    Node* head = ConvertArrtoDLL(arr);
    head = deletehead(head);
    print(head);
    head = deleteElement(head,33);
    print(head);
    head = deleteTail(head);
    print(head);
    return 0;
}
