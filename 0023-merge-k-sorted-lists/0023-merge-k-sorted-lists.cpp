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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)  return list2;
        if(!list2)  return list1;
        ListNode*res=list1;
        if(list2->val<=list1->val)   {
            res=list2;
            list2=list2->next;
        }
        else{
            list1=list1->next;
        }
         ListNode*ans=res;
        while(list1 && list2){
            if(list1->val<=list2->val){
                ans->next=list1;
                list1=list1->next;
            }
            else{
                ans->next=list2;
                list2=list2->next;
            }
            ans=ans->next;
        }
        if(list1){
            ans->next=list1;
        }
        else{
            ans->next=list2;
        }
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)  return NULL;
        ListNode*ans=lists[0];
        for(int i=1;i<lists.size();i++){
            ans=mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }
};