class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int mxdp=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
                mxdp=max(mxdp,cnt);
            }
            else if(s[i]==')'){
                cnt--;
                mxdp=max(mxdp,cnt);
            }
        }
        return mxdp;
    }
};