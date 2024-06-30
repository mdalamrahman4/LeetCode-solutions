class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot_sum=accumulate(nums.begin(),nums.end(),0);
        int sum;
        if(tot_sum%2)   return false;
        else{
            tot_sum/=2;
        }
        vector<vector<bool>>dp(n,vector<bool>(tot_sum+1,false));
        for(int i=0;i<n;i++)    dp[i][0]=true;
        if(nums[0]<=tot_sum) dp[0][nums[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int sum=1;sum<=tot_sum;sum++){
                int nottake=dp[ind-1][sum];
                int take=false;
                if(nums[ind]<=sum){
                    take=dp[ind-1][sum-nums[ind]];
                }
                dp[ind][sum]=take|nottake;
            }
        }
        return dp[n-1][tot_sum];
    }
};