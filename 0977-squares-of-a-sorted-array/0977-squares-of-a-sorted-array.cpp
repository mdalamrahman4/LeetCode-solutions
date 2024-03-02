class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        int low=0,high=n-1;
        for(int i=n-1;i>=0;i--){
            if(abs(nums[low])>=abs(nums[high])){
                res[i]=(nums[low]*nums[low++]);
            }
            else{
                res[i]=(nums[high]*nums[high--]);
            }
        }
        return res;
    }
};