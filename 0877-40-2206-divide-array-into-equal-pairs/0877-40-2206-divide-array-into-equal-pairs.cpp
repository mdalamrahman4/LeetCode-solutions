class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>freq(501,0);
        for(auto it:nums){
            freq[it]++;
        }
        for(auto it:freq){
            if(it%2!=0) return false;
        }
        return true;
    }
};