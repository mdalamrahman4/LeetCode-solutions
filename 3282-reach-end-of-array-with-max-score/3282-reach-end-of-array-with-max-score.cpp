class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n=nums.size(),i=0;
        long long ans=0;
        for(int j=1;j<n;j++){
            if(nums[j]>=nums[i]){
                ans+=1LL*(j-i)*nums[i];
                i=j;
            }
            else if(j==n-1){
                ans+=1LL*(n-i-1)*nums[i];
            }
        }
        return ans;
    }
};