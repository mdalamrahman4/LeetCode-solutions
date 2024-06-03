class Solution {
public:
    string clearStars(string s) {
        vector<int>freq[26];
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                for(auto &p:freq){
                    if(!p.empty()){
                        s[p.back()]='*';
                        p.pop_back();
                        break;
                    }
                }
            }
            else{
                freq[s[i]-'a'].push_back(i);
            }
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
    }
};