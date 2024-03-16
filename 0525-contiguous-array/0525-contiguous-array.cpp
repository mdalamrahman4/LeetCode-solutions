class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            (nums[i]==1)?nums[i]=1:nums[i]=-1;
        }
        int sum=0;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum)!=mp.end()){
                mx=max(mx,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return mx;
    }
};