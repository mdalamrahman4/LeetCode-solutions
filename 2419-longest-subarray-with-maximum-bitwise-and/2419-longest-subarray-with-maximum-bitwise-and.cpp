class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int cnt=0,mxcnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mx){
                cnt++;
                mxcnt=max(mxcnt,cnt);
            }
            else{
                cnt=0;
            }
        }
        return mxcnt;
    }
};