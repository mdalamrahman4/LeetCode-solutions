class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=1,last=0;
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            temp.push_back(nums[last]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};