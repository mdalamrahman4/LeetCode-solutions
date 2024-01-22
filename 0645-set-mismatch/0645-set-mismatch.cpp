class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int fullsum=accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int sum=accumulate(nums.begin(),nums.end(),0);
        int repeatedno=fullsum-sum;
        int missingno=(n*(n+1))/2-sum;
        return {repeatedno,missingno};
    }
};