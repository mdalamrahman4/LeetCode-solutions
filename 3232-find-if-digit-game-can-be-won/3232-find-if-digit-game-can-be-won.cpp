class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum=0;
        for(auto&it:nums){
            sum+=(it<10)?it:-it;
        }
        return sum!=0;
    }
};