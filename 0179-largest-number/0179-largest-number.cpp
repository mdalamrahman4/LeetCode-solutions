class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(begin(nums),end(nums),[](int &a,int &b){
            return ((to_string(a)+to_string(b))>(to_string(b)+to_string(a)));
        });
        string ans="";
        for(auto &it:nums){
            ans+=to_string(it);
        }
        return ans[0]=='0'?"0":ans;
    }
};