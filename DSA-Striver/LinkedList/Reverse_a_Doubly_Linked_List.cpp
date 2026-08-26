/*
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
*/

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* current = head;
        ListNode* last = NULL;
        while(current!=NULL){
            last=current->prev;
            current->prev=current->next;
            current->next=last;
            current=current->prev;
        }
        return last->prev;
        
    }
};
