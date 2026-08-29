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
    int findLengthOfLoop(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return 0;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                ListNode* startPt = slow;
                fast = fast->next;
                int cnt = 1;
                while(fast!=startPt){
                    cnt++;
                    fast=fast->next;
                }
                return cnt;
            }
        }
        return 0;

    }
};
