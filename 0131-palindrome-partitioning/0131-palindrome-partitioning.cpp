class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        check(0,s,ds,ans);
        return ans;
    }
    void check(int ind,string s,vector<string>&ds,vector<vector<string>>&ans)
    {
        if(ind==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(ispalin(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                check(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    bool ispalin(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};