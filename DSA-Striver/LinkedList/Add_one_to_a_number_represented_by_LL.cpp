/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode *addOne(ListNode *head) {
        
        ListNode* reversedHead = reverseList(head);
        int carry=1;
        ListNode* curr = reversedHead;
        ListNode* last = NULL;
        while(curr!=NULL){
            int sum = curr->val + carry;
            curr->val= sum % 10;
            carry = sum / 10;
            last=curr;
            if(carry==0){
                break;
            }
            curr=curr->next;
        }
        if (carry > 0) 
        {
            last->next = new ListNode(carry);
        }
        return reverseList(reversedHead);

    }
};
