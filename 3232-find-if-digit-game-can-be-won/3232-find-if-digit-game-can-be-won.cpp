class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum=0;
        for(int it:nums){
            sum+=(it<10)?it:-it;
        }
        return sum!=0;
    }
};