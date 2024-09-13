class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int>xory;
        for(auto it:queries){
            int prev=0;
            for(int i=it[0];i<=it[1];i++){
                prev^=arr[i];
            }
            xory.push_back(prev);
        }
        return xory;
    }
};