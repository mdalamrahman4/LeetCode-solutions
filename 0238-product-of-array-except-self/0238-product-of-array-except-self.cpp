class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n,1),prefix(n,1);
        prefix[0]=nums[0],suffix[n-1]=nums[n-1];
        for(int i=0;i<n-1;i++){
            prefix[i+1]=prefix[i]*nums[i+1];
        }
        for(int j=n-2;j>=0;j--){
            suffix[j]=suffix[j+1]*nums[j];
        }
        vector<int>ans(n,1);
        ans[0]=suffix[1],ans[n-1]=prefix[n-2];
        for(int i=1;i<n-1;i++){
            ans[i]=prefix[i-1]*suffix[i+1];
        }
        return ans;
    }
};