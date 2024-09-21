class Solution {
public:
    void solve(int no,int n,vector<int>&res){
        if(no>n)    return;
        res.push_back(no);
        for(int i=0;i<=9;i++){
            int currno=no*10+i;
            if(currno>n)    return;
            solve(currno,n,res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int startno=1;startno<=9;startno++){
            solve(startno,n,res);
        }
        return res;
    }
};