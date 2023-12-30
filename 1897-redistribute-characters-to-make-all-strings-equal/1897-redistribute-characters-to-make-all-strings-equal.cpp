class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int>mp;
        for(auto &k:words){
            for(int i=0;i<k.size();i++){
                mp[k[i]]++;
            }
        }
        for(auto &k:mp){
            if(k.second%words.size())
                return false;
        }
        return true;
    }
};