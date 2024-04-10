class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp[k-nums[i]]>0){
                count++;
                mp[k-nums[i]]--;
            }
            else{
                mp[nums[i]]++;
            }
        }
        return count;
    }
};