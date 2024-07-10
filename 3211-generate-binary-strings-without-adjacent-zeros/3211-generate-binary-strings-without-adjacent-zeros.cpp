class Solution {
public:
    vector<string>ans;
    void f(int ind,string str,int n){
        if(ind>=n){
            ans.push_back(str);
            return;
        }
        if(str[ind-1]=='0'){
            f(ind+1,str+'1',n);
        }
        else{
            f(ind+1,str+'0',n);
            f(ind+1,str+'1',n);
        }
    }
    vector<string> validStrings(int n) {
        string str="0";
        f(1,str,n);
        str="1";
        f(1,str,n);
        return ans;
    }
};