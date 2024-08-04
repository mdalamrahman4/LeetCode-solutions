class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>temp;
        int mod=(1e9+7);
        for(int i=0;i<n;i++){
            int sum=nums[i];
            temp.push_back(sum);
            for(int j=i+1;j<n;j++){
                sum=(sum+nums[j])%mod;
                temp.push_back(sum);
            }
        }
        sort(temp.begin(),temp.end());
        int ans=0;
        for(int i=left;i<=right;i++){
            ans=(ans+temp[i-1])%mod;
        }
        return ans%mod;
    }
};