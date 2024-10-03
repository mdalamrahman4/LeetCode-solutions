class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%p;
        }
        int target=sum%p;
        if(target==0)   return 0;
        int curr=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int res=n;
        for(int j=0;j<n;j++){
            curr=(curr+nums[j])%p;
            int remain=(curr-target+p)%p;
            if(mp.find(remain)!=mp.end()){
                res=min(res,j-mp[remain]);
            }
            mp[curr]=j;
        }
        return res==n?-1:res;
    }
};