class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end()),
        high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int count=1,currsubarraysum=0;
            for(int i=0;i<nums.size();i++){
                if(currsubarraysum+nums[i]<=mid){
                    currsubarraysum+=nums[i];
                }
                else{
                    count++;
                    currsubarraysum=nums[i];
                }
            }
            if(count<=k)    high=mid-1;
            else    low=mid+1;
        }
        return low;
    }
};