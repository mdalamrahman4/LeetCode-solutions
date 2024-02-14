class Solution {
    void f(string op, int open, int close, vector<string> &ans){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }
        //when count of open and close brackets are same then 
        //we have only one choice to put open bracket 
        if(open == close){
            op.push_back('(');
            f(op, open-1, close, ans);
        }
        else if(open == 0){
            //only choice is to put close brackets 
            op.push_back(')');
            f(op, open, close-1, ans);
        }
        else if(close == 0){
            //only choise is to use open bracket 
            op.push_back('(');
            f(op, open-1, close, ans);
        }
        else{
            string op1 = op;
            string op2 = op;
            op1.push_back('(');
            op2.push_back(')');
            f(op1, open-1, close, ans);
            f(op2, open, close-1, ans);
        }
    }
    public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string op = "";
        f(op, n, n, ans);
        return ans;
    }
};