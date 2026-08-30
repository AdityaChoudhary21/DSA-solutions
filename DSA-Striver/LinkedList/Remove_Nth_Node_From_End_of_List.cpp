/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(n==cnt){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* front = head;
        int startpt = cnt - n;
        ListNode* prev = NULL;
        for(int i = 1; i<=startpt; i++){
            prev = front;
            front=front->next;
        }
        prev->next=prev->next->next;
        delete front ;
        return head;
    }
};
