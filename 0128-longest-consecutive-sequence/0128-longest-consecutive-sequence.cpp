class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<=1)    return n;
        int longest=1;
        int cnt=1;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev+1){
                cnt++;
                longest=max(longest,cnt);
            }
            else if(nums[i]!=prev){
                cnt=1;
            }
            prev=nums[i];
        }
        return longest;
    }
};