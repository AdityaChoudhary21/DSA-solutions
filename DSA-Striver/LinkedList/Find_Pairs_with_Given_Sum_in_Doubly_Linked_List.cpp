/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> arr;
        if (head == NULL || head->next == NULL) return arr;
        ListNode* tail = head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        ListNode* left = head;
        ListNode* right = tail;

        while(left->val < right->val){
            int sum = left->val + right->val;
            if(sum==target){
                arr.push_back({left->val ,right->val});
                left=left->next;
                right=right->prev;
            }
            else if(sum < target){
                left=left->next;
            }
            else{
                right=right->prev;
            }
        }
        return arr;
    }
};

