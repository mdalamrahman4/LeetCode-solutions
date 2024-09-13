class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>prexor(n+1,0);
        for(int i=1;i<=n;i++){
            prexor[i]=prexor[i-1]^arr[i-1];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int curr=prexor[queries[i][0]]^prexor[queries[i][1]+1];
            ans.push_back(curr);
        }
        return ans;
    }
};