class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(auto &it:s){
            if(!st.empty() && it=='B' && st.top()=='A')    st.pop();
            else if(!st.empty() && it=='D' && st.top()=='C')   st.pop();
            else st.push(it);
        }
        return st.size();
    }
};