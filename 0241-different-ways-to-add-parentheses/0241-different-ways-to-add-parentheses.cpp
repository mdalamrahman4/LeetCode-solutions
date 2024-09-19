class Solution {
public:
    vector<int>f(string exp){
        vector<int>ans;
        int n=exp.size();
        for(int i=0;i<n;i++){
            if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*'){
                vector<int>left_res=f(exp.substr(0,i));
                vector<int>right_res=f(exp.substr(i+1));
                for(auto &x:left_res){
                    for(auto &y:right_res){
                        if(exp[i]=='+'){
                            ans.push_back(x+y);
                        }
                        else if(exp[i]=='-'){
                            ans.push_back(x-y);
                        }
                        else{
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(ans.empty()){
                ans.push_back(stoi(exp));
            }
            return ans;
    }
    vector<int> diffWaysToCompute(string exp) {
        return f(exp);
    }
};