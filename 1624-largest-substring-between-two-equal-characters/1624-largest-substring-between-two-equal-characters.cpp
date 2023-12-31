class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,int>mp;
        int mx = -1;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end()){
                int c = (i-mp[s[i]])-1;
                mx = max(mx, c);
            }
            else mp[s[i]]=i;
        }
        return mx;
    }
};