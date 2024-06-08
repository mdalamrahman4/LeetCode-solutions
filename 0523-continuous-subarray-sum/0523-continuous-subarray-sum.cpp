class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0,n=nums.size();
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)   rem+=k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>1) return true;
            }
            else{
                mp[rem]=i;
            }
        }
        return false;
    }
};