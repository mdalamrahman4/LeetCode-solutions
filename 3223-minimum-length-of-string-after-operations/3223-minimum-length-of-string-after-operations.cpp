class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(auto &it:s){
            mp[it]++;
        }
        int n=s.size(),cnt=0;
        for(auto it:mp){
            int x=it.second;
            cnt+=(x%2)?x-1:x-2;
        }
        return n-cnt;
    }
};