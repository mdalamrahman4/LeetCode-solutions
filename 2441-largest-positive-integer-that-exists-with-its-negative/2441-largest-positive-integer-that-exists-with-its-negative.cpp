class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp.insert(nums[i]);
        }
        int mx=-1;
        for(auto &it:mp){
            if(mp.find(-it)!=mp.end()  && abs(it)>mx){
                mx=it;
            }
        }
        return mx;
    }
};