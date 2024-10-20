class Solution {
public:
    char solveop(char op,vector<char>&values){
        if(op=='!') return values[0]=='t'?'f':'t';
        if(op=='&') return any_of(values.begin(),values.end(),[](char ch){
            return ch=='f';
        })?'f':'t';
        else return any_of(values.begin(),values.end(),[](char ch){
            return ch=='t';
        })?'t':'f';
    }
    bool parseBoolExpr(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==',')   continue;
            if(s[i]==')'){
                vector<char>values;
                while(st.top()!='('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.top();
                st.push(solveop(op,values));
            }else{
                st.push(s[i]);
            }
        }
        return st.top()=='t';
    }
};