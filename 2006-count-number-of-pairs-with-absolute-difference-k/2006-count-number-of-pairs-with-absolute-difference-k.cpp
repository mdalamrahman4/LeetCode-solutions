class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt=0;
        for(auto it:nums){
            cnt+=(mp[it-k]+mp[it+k]);
            mp[it]++;
        }
        return cnt;
    }
};