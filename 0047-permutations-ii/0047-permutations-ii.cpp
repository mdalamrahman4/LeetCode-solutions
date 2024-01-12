class Solution {
public:
    void check(int ind,vector<vector<int>>&ans,vector<int>nums) {
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++) {
            if(i!=ind && nums[ind]==nums[i]) continue;
            swap(nums[ind],nums[i]);
            check(ind+1,ans,nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        check(0,ans,nums);
        return ans;
    }
};
/*class Solution {
public:
    void recur(vector<vector<int>> &ans, vector<int> nums, int index)
    {
        if(index == nums.size())
        {
            ans.emplace_back(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++)
        {
            if(i != index && nums[i] == nums[index])
                continue;
            swap(nums[i], nums[index]);
            recur(ans, nums, index+1);
        }

    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        recur(ans, nums, 0);
        return ans;
    }
};*/