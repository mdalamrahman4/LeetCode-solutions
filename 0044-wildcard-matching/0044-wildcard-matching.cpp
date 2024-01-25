class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<bool>prev(m+1,false),curr(m+1,false);
        prev[0]=true;
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int x=1;x<=i;x++)
            {
                if(p[x-1]!='*')   flag=false;
            }
            curr[0]=flag;
            for(int j=1;j<=m;j++){
                if(s[j-1]==p[i-1] || p[i-1]=='?')  curr[j]=prev[j-1];
                else if(p[i-1]=='*')   curr[j]=prev[j]|curr[j-1];
                else curr[j]=false;
            }
            prev=curr;
        }
        return prev[m];
    }
};