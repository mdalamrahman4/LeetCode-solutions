class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
    int atmost(vector<int>&nums,int goal){
        if(goal<0)  return 0;
        int n=nums.size();
        int i=0,j=0;
        int sum=0;
        int ans=0;
        while(j<n){
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i++];
            }
            ans+=(j++-i+1);
        }
        return ans;
    }
};