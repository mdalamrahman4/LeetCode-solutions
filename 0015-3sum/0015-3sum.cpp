class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int start=i+1,end=n-1;
            while(start<end){
                int target=nums[i]+nums[start]+nums[end];
                if(target==0){
                    st.insert({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                }
                else if(target<0)   start++;
                else end--;
            }
        }
        for(auto &it:st){
            ans.push_back(it);
        }
        return ans;
    }
};