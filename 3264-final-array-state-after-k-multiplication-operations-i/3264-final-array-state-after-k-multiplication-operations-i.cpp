class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        for(int i=0;i<k;i++){
            auto q=pq.top();
            pq.pop();
            int ind=q.second;
            int ele=q.first;
            nums[ind]=ele*multiplier;
            pq.push({nums[ind],ind});
        }
        return nums;
    }
};