class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>freq(201,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]+100]++;
        }
        sort(nums.begin(),nums.end(),[&](int x,int y){
            return freq[x+100]==freq[y+100]?x>y:freq[x+100]<freq[y+100];
        });
        return nums;
    }
};