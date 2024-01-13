class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>s1,t1;
        for(int i=0;i<s.size();i++){
            if(s1[s[i]] && s1[s[i]]!=t[i])  return false;
            if(t1[t[i]] && t1[t[i]]!=s[i])  return false;
            s1[s[i]]=t[i];
            t1[t[i]]=s[i];
        }
        return true;
    }
};