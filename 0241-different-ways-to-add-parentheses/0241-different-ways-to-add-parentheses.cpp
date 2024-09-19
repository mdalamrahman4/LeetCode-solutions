class Solution {
public:
    unordered_map<string,vector<int>>mp;
    vector<int>f(string exp){
        vector<int>ans;
        int n=exp.size();
        for(int i=0;i<n;i++){
            if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*'){
                string str1=exp.substr(0,i),str2=exp.substr(i+1);
                vector<int>left_res;
                if(mp.find(str1)!=mp.end())
                   left_res=mp[str1];
                else    left_res=f(str1);
                vector<int>right_res;
                if(mp.find(str2)!=mp.end()){
                    right_res=mp[str2];
                }
                else    right_res=f(str2);
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
        mp[exp]=ans;
        return ans;
    }
    vector<int> diffWaysToCompute(string exp) {
        return f(exp);
    }
};