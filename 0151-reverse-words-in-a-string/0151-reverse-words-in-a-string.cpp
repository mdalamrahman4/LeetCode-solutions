class Solution {
public:
    string reverseWords(string s) {
        int start=0;
        while(s[start]==' '){
            start++;
        }
        int end=s.size()-1;
        while(s[end]==' '){
            end--;
        }
        string ans="";
        string word="";
        stack<string>st;
        for(int i=start;i<=end;i++){
            if(s[i]==' ' && word.size()>0 && word[0]!=' '){
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