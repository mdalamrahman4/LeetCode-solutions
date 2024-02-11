class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool>count(26,0);
        for(char &c:s){
            if(count[c-'a']==true) return c;
            count[c-'a']=true;
        }
        return 'a';
    }
};