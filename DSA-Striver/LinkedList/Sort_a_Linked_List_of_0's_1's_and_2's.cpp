/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            if(head==NULL || head->next==NULL){
            return head;
            }
            ListNode* zerohead = new ListNode (-1);
            ListNode* onehead = new ListNode (-1);
            ListNode* twohead = new ListNode (-1);
            ListNode* temp = head;
            ListNode* zero = zerohead;
            ListNode* one = onehead;
            ListNode* two = twohead;

            while(temp!=NULL){
                if(temp->data == 0){
                    zero->next=temp;
                    zero=zero->next;
                }
                else if(temp->data == 1){
                    one->next=temp;
                    one=one->next;
                }
                else{
                    two->next=temp;
                    two=two->next;
                }
                temp=temp->next;
            }

            zero->next = (onehead->next) ? onehead->next : twohead->next;
            one->next = twohead->next;
            two->next = NULL;

            ListNode* newhead=zerohead->next;

            delete zerohead;
            delete onehead;
            delete twohead;
            return newhead;
            
        }
};
