class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0,res=-1e9;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i<k){
                sum+=nums[i];
            }
            else{
                res=max(sum,res);
                sum+=(nums[i]-nums[i-k]);
            }
        }
        res=max(res,sum);
        return (res/k);
    }
};