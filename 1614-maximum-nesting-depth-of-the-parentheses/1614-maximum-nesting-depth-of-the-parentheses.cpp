class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int mxdp=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
                int t=st.size();
                mxdp=max(mxdp,t);
            }
            else if(s[i]==')'){
                st.pop();
            }
        }
        return mxdp;
    }
};