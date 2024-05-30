class Solution {
public:
    int sliding(vector<int>&nums,int target){
        if(target<0)    return 0;
        int cnt=0;
        int l=0,r=0,n=nums.size();
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>target){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sliding(nums,goal)-sliding(nums,goal-1);
    }
};