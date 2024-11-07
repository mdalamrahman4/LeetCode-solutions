class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int n=nums.size();
        int c=0,maxi=0;
        for(int i=0;i<32;i++){
            c=0;
            for(int j=0;j<n;j++){
                if(nums[j] & (1<<i)){
                    c++;
                }
            }
            maxi=max(maxi,c);
        }
        return maxi;
    }
};