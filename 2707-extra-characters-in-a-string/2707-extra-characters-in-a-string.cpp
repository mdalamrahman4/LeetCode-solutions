class Solution {
public:
    int f(int ind,string &s,unordered_set<string> &st,int n,unordered_map<int,int>&mp){
        if(ind>=n)  return 0;
        if(mp.count(ind))   return mp[ind];
        int res=1+f(ind+1,s,st,n,mp);
        for(int j=ind;j<n;j++){
            string curr=s.substr(ind,j-ind+1);
            if(st.count(curr)){
                res= min(res,f(j+1,s,st,n,mp));
            }
        }
        return mp[ind]=res;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n=s.size();
        unordered_set<string>st(dict.begin(),dict.end());
        unordered_map<int,int>mp;
        return f(0,s,st,n,mp);
    }
};