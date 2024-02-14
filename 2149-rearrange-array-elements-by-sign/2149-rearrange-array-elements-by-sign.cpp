class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>arrp;
        vector<int>arrn;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                arrn.push_back(nums[i]);
            }
            else{
                arrp.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=arrp[i/2];
            }
            else{
                nums[i]=arrn[i/2];
            }
        }
        return nums;
    }
};