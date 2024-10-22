class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long sum=0,mxsum=0;
        int i=0,n=nums.size();
        for(int j=0;j<n;j++){
            sum+=nums[j];
            mp[nums[j]]++;
            if(j-i+1==k){
                if(mp.size()==k){
                    mxsum=max(mxsum,sum);
                }
                sum-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0)  mp.erase(nums[i]);
                i++;
            }
        }
        return mxsum;
    }
};