class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask=0;
        for(char &ch:allowed){
            mask|=(1<<(ch-'a'));
        }
        int cnt=0;
        for(string &it:words){
            for(char ch:it){
                if((mask>>(ch-'a')&1)==0){
                    cnt++;
                    break;
                }
            }
        }
        return words.size()-cnt;
    }
};