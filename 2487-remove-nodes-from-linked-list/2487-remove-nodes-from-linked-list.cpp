

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* node=head,*finalAns=head;
        
        st.push(node);
        node = node->next;
        
        while(node!=NULL){
            
            while(node && st.size() && st.top()->val < node->val){
                st.pop();
            }
            
            if(st.size() == 0){
                finalAns = node;
            }
            else{
                st.top()->next = node;
            }
            st.push(node);
            node=node->next;
        }
        return finalAns;
    }
};