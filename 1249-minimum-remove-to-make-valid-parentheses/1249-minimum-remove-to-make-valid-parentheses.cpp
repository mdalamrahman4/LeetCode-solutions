class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    s[i]='#';
                }
            }
        }
        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }
        string ans="";
        for(auto &it:s){
            if(it!='#'){
                ans+=it;
            }
        }
        return ans;
    }
};