class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans="";
        int i;
        for(i=0;i<s.size();i++){
            if(s[i]-'a'<=k || 'z'-s[i]+1<=k){
                ans+='a';
                k-=min(s[i]-'a',('z'-s[i]+1));
            }
            else{
                ans+=(s[i]-k);
                break;
            }
        }
        i++;
        for(;i<s.size();i++){
            ans+=s[i];
        }
        return ans;
    }
};