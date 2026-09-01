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
    ListNode* findmiddle(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummynode = new ListNode (-1);
        ListNode* temp = dummynode;
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1){
            temp->next=list1;
        }
        else{
            temp->next=list2;
        }
        ListNode* result = dummynode->next;
        delete dummynode;
        return result;
    }

    ListNode* sortLL(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middle = findmiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;
        middle->next=nullptr;

        lefthead=sortLL(lefthead);
        righthead=sortLL(righthead);
        return merge(lefthead,righthead);
    }

    ListNode* sortList(ListNode* head) {
        return sortLL(head);
    }
};


