class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int>mp;
        string temp="";
        for(int i=0;i<paragraph.size();i++){
            paragraph[i]=tolower(paragraph[i]);
            if(!isalpha(paragraph[i]) && temp!="" ){
                mp[temp]++;
                temp="";
            }
            else{
                if(paragraph[i]!=' ')   temp+=paragraph[i];
            }
        }
        if(temp!="") mp[temp]++;
        for(auto it:banned){
            mp[it]=0;
        }
        int freq=0;
        string ans="";
        for(auto it:mp){
            if(it.second>freq){
                ans=it.first;
                freq=it.second;
            }
        }
        return ans;
    }
};