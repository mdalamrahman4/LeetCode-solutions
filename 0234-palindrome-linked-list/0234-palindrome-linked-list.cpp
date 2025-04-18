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
    ListNode*reverselist(ListNode*head){
        ListNode*prev=NULL,*curr=head,*nxtnode;
        while(curr){
            nxtnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxtnode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)    return true;
        ListNode*slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverselist(slow->next);
        slow=slow->next;
        while(slow){
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};