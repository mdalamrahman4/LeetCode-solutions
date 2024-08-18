class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int one=0,zero=0,n=s.size(),j=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') zero++;
            else    one++;
            while(zero>k && one>k){
                if(s[j]=='0')   zero--;
                else    one--;
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};