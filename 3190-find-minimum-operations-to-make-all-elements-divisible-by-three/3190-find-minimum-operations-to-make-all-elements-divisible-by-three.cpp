class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int rem=nums[i]%3;
            if(rem==1 || rem==2)    cnt++;
        }
        return cnt;
    }
};