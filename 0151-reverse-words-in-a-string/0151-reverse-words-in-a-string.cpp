class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string word="";
        stack<string>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && word.size()>0){
                st.push(word);
                word="";
            }
            else{
                if(s[i]!=' ') word+=s[i];
            }
        }
        if(word.size()){
            st.push(word);
        }
        while(!st.empty()){
            ans+=st.top();
            if(st.size()>1) ans+=' ';
            st.pop();
        }
        return ans;
    }
};