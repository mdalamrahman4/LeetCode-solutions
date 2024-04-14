class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        unordered_set<int>st={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        int n=nums.size();
        int i=0,j=n-1;
        while(i<=j){
            auto it=st.find(nums[i]);
            auto notit=st.find(nums[j]);
            if(it!=st.end() && notit!=st.end()){
                return j-i;
            }
            else if(it!=st.end()){
                j--;
            }
            else if(notit!=st.end()){
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        return 0;
    }
};