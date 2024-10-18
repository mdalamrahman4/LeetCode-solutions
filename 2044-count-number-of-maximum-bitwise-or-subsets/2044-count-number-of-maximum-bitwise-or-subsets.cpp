class Solution {
public:
    int f(int ind,int curror,int xr,vector<int>&nums){
        if(ind==nums.size()){
            if(curror==xr)  return 1;
            return 0;
        }
        int take=f(ind+1,curror|nums[ind],xr,nums);
        int nottake=f(ind+1,curror,xr,nums);
        return take+nottake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int xr=0;
        for(int &it:nums)   xr|=it;
        return f(0,0,xr,nums);
    }
};