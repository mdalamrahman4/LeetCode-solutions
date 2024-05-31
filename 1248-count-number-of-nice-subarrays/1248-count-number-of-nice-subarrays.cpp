class Solution {
public:
    int sliding(vector<int>&nums,int k){
        if(k<0) return 0;
        int l=0,r=0,n=nums.size(),sum=0,cnt=0;
        while(r<n){
            if(nums[r]%2==1)  sum++;
            while(sum>k){
                if(nums[l]%2)   sum--;
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return sliding(nums,k)-sliding(nums,k-1);
    }
};