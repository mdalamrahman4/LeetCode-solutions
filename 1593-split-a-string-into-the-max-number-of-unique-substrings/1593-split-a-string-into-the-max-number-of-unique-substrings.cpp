class Solution {
public:
    unordered_set<string>st;
    int cnt=0;
    void f(int ind,string &s){
        if(st.size()>cnt)   cnt=st.size();
        if(ind>=s.size())   return;
        string temp="";
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(st.count(temp)==0){
                st.insert(temp);
                f(i+1,s);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        f(0,s);
        return cnt;
    }
};