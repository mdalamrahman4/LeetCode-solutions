class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>freq(nums.size(),0);
        check(ds,ans,nums,freq);
        return ans;
    }
    void check(vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums,vector<int>freq){
        if(ds.size()==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]++;
                check(ds,ans,nums,freq);
                ds.pop_back();
                freq[i]=0;
            }
        }
    }
};