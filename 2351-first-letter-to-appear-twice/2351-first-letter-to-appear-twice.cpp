class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int>count(26,0);
        for(char &c:s){
            if(count[c-'a']==1) return c;
            count[c-'a']++;
        }
        return 'a';
    }
};