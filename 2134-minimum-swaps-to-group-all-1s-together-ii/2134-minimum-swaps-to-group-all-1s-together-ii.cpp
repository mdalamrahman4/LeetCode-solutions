class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int n1=count(nums.begin(),nums.end(),1);
        int cnt=0,mswap=1e9,i=0;
        for(int j=0;j<n+n1;j++){
            cnt+=nums[j%n];
            if(j-i+1>n1){
                cnt-=nums[i%n];
                i++;
            }
            if(j-i+1==n1){
                mswap=min(mswap,n1-cnt);
            }
        }
        return mswap;
    }
};