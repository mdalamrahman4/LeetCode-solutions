class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int mx=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int root=sqrt(nums[i]);
            if(root*root==nums[i]){
                mp[nums[i]]=1+mp[root];
            }
            else{
                mp[nums[i]]=1;
            }
            mx=max(mx,mp[nums[i]]);
        }
        return mx < 2 ? -1 : mx;
    }
};