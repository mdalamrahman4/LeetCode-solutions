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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int row=0,rowend=m-1,col=0,colend=n-1;
        vector<vector<int>>ans(m,vector<int>(n,-1));
        while(head){
            for(int i=col;i<=colend && head;i++){
                ans[row][i]=head->val;
                head=head->next;
            }
            row++;
            for(int j=row;j<=rowend && head;j++){
                ans[j][colend]=head->val;
                head=head->next;
            }
            colend--;
            for(int i=colend;i>=col && head;i--){
                ans[rowend][i]=head->val;
                head=head->next;
            }
            rowend--;
            for(int j=rowend;j>=row && head;j--){
                ans[j][col]=head->val;
                head=head->next;
            }
            col++;
        }
        return ans;
    }
};