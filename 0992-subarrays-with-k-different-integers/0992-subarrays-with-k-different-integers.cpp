class Solution {
public:
    int sliding(vector<int>&nums,int k){
        if(k<0) return 0;
        int l=0,r=0,n=nums.size(),cnt=0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)  mp.erase(nums[l]);
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sliding(nums,k)-sliding(nums,k-1);
    }
};