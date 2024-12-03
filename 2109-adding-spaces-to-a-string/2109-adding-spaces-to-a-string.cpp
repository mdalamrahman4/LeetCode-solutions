class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int j=0,m=spaces.size(),n=s.size();
        for(int i=0;i<n;i++){
            if(j<m && i==spaces[j]){
                ans+=" ";
                j++;
                ans+=s[i];
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};