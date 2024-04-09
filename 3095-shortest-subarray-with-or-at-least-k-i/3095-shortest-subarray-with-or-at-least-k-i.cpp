class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int mn=nums.size()+1;
        for(int s=0;s<nums.size();s++){
            int oor=0;
            for(int j=s;j<nums.size();j++){
                oor=oor|nums[j];
                if(oor>=k) mn=min(mn,j-s+1);
            }
        }
        return (mn==nums.size()+1)?-1:mn;
    }
};