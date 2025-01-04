class Solution {
public:
    bool hasMatch(string s, string p) {
        int ind=p.find('*');
        string prefix=p.substr(0,ind);
        string post=p.substr(ind+1);
        int prefixindexend=s.find(prefix)+prefix.size();
        if(s.find(prefix)==string::npos)    return false;
        return s.find(post,prefixindexend)!=string::npos;
    }
};