class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(auto &it:nums){
            if(++mp[it]>1) return true;
        }
        return false;
    }
};