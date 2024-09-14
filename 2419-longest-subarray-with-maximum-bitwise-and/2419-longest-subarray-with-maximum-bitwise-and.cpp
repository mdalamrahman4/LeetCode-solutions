class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt=0,mxcnt=0,mxval=0;
        for(auto it:nums){
            if(it>mxval){
                mxval=it;
                cnt=0;
                mxcnt=0;
            }
            if(it==mxval){
                cnt++;
            }
            else{
                cnt=0;
            }
            mxcnt=max(mxcnt,cnt);
        }
        return mxcnt;
    }
};