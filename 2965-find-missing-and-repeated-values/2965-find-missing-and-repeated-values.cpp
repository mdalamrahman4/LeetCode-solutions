class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>count(2501,0);
        int n=grid.size(),m=grid[0].size();
        int sum=0,repeat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(count[grid[i][j]]==1) repeat=grid[i][j];
                else{
                    sum+=grid[i][j];
                    count[grid[i][j]]=1;
                }
            }
        }
        int total=(n*m*(n*m+1))/2;
        return {repeat,total-sum};
    }
};