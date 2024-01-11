class Solution {
public:
    void f(int ind,set<vector<int>>&st,vector<int>ans,vector<int>&arr)
    {
        if(ind==arr.size())
        {
            sort(ans.begin(),ans.end());
            st.insert(ans);
            return;
        }
        ans.push_back(arr[ind]);
        f(ind+1,st,ans,arr);
        ans.pop_back();
        f(ind+1,st,ans,arr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>ans;
        vector<vector<int>>v;
        f(0,st,ans,nums);
        for(auto &it:st)
            v.push_back(it);
        return v;
    }
};