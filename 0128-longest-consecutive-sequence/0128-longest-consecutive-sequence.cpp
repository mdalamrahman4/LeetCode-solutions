class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)    return 0;
        int longest=1;
        int cnt=0;
        sort(nums.begin(),nums.end());
        int prev=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==prev+1){
                cnt++;
            }
            else if(nums[i]!=prev){
                cnt=1;
            }
            prev=nums[i];
            longest=max(longest,cnt);
        }
        return longest;
    }
};