class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c); // Convert to lowercase to handle both cases
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k) {
        int cnt=0,mx=0;
        for(int i=0;i<s.size();i++)
        {
            if(i<k){
                if(isVowel(s[i]))   cnt++;
            }
            else{
                mx=max(mx,cnt);
                if(isVowel(s[i]) && !isVowel(s[i-k])) cnt++;
                else if(!isVowel(s[i]) && isVowel(s[i-k])) cnt--;
            }
        }
        mx=max(mx,cnt);
        return mx;
    }
};