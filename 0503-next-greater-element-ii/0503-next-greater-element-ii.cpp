class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }
            if(i<n){
                arr[i]=(st.empty())?-1:st.top();
            }
            st.push(nums[i%n]);
        }
        return arr;
    }
};