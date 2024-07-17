class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto &c:s){
            if(!st.empty()){
                if(c==')' && st.top()=='('){
                    st.pop();
                    continue;
                }
                else if(c=='}' && st.top()=='{'){
                    st.pop();
                    continue;
                }
                else if(c==']' && st.top()=='['){
                    st.pop();
                    continue;
                }
            }
            if(c==')' || c=='}' || c==']'){
                    return false;
            }
            else{
                st.push(c);
            }
        }
        return st.empty();
    }
};