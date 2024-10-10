class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>rmax(n);
        rmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],nums[i]);
        }
        int low=0,high=1;
        int mx=0;
        while(high<n){
            if(nums[low]<=rmax[high]){
                mx=max(mx,high-low);
                high++;
            }
            else{
                low++;
            }
        }
        return mx;
    }
};