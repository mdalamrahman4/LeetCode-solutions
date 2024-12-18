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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        ListNode*newhead=new ListNode(0);
        newhead->next=head;
        ListNode*prev=newhead;
        ListNode*curr=head;
        while(curr){
            if(st.find(curr->val)!=st.end()){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        ListNode*result=newhead->next;
        delete newhead;
        return result;
    }
};