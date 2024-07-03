class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int mxindex=0;
        for(int i=0;i<n;i++){
            if(i>mxindex)   return false;
            mxindex=max(mxindex,i+nums[i]);
        }
        return true;
    }
};