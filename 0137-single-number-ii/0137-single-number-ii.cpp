class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bits=0;bits<=31;bits++){
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&(1<<bits))   cnt++;
            }
            if(cnt%3==1){
                ans=ans|(1<<bits);
            }
        }
        return ans;
    }
};