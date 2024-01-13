class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>s1;
        unordered_map<char,char>t1;
        for(int i=0;i<s.size();i++)
        {
            if(s1.find(s[i])!=s1.end()){
                if(s1[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
                s1[s[i]]=t[i];
            }
            if(t1.find(t[i])!=t1.end()){
                if(t1[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
                t1[t[i]]=s[i];
            }
        }
        return true;
    }
};