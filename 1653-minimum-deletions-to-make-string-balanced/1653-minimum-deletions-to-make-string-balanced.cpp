class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int n=s.size();
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(!st.empty() && st.top()<s[i]){
                cnt++;
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        return cnt;
    }
};