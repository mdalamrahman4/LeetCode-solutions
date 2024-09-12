class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool>freq(26,false);
        int cnt=0;
        for(char c:allowed) freq[c-'a']=true;
        for(string word:words){
            for(char c:word)    {
                if(!freq[c-'a']){
                    cnt++;
                    break;
                }
            }
        }
        return words.size()-cnt;
    }
};