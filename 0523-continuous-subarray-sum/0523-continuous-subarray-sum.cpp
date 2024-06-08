class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=nums[0];
        for(int r=1;r<n;r++){
            if(nums[r]==0 && nums[r-1]==0){
                return true;
            }
            sum+=nums[r];
            if(sum%k==0)    return true;
            int tempsum=sum,l=0;
            while(r>l+1 && tempsum>=k){
                tempsum-=nums[l];
                if(tempsum%k==0)    return true;
                l++;
            }
        }
        return false;
    }
};