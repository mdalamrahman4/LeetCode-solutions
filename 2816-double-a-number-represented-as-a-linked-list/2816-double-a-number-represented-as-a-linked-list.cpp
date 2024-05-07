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
    ListNode*rev(ListNode*head){
        ListNode*prev=NULL,*curr=head,*temp;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode*ans=rev(head);
        ListNode*copy=ans;
        ListNode*last=copy;
        int carry=0;
        while(copy){
            int t=copy->val;
            t=t*2;
            copy->val=(t+carry)%10;
            carry=(t+carry)/10;
            last=copy;
            copy=copy->next;
        }
        while (carry) {
        last->next = new ListNode(carry % 10);
        carry = carry / 10;
        last = last->next;
    }
        return rev(ans);
    }
};