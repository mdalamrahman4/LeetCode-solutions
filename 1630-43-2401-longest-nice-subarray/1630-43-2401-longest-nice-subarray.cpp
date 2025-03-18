class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0;
        int mask=0;
        int result=1;
        for(int j=0;j<nums.size();j++){
            while(mask&nums[j]){
                mask^=nums[i++];
            }
            result=max(result,j-i+1);
            mask|=nums[j];
        }
        return result;
    }
};