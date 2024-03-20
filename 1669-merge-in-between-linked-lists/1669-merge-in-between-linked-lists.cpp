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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt1=0,cnt2=0;
        ListNode*copy=list1;
        while(copy && ++cnt1<a){
            copy=copy->next;
        }
        ListNode*temp1=copy;
        while(copy && ++cnt1<=b+1){
            copy=copy->next;
        }
        ListNode*temp2=copy->next;
        temp1->next=list2;
        while(temp1->next){
            temp1=temp1->next;
        }
        temp1->next=temp2;
        return list1;
    }
};