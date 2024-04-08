class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int icnt=1,dcnt=1;
        int m=1,n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                icnt++;
                dcnt=1;
            }
            else if(nums[i]<nums[i-1]){
                dcnt++;
                icnt=1;
            }
            else {
                icnt=1;
                dcnt=1;
            }
            m=max(m,max(icnt,dcnt));
        }
        return m;
    }
};