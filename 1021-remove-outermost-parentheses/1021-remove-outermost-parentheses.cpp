class Solution {
public:
    string removeOuterParentheses(string s) {
        string str="";
        int count=0;
        for(int i=0;i<s.size();i++)
        { 
            if(s[i]=='('){
            if(count++ ){
                str+='(';
            }
            }
            else 
            {
                if (--count)
            {
                str+=')';
            }
            }
        }
        return str;
    }
};