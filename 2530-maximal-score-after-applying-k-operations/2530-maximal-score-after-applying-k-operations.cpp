class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        long long sum=0;
        while(k--){
            int no=pq.top();
            sum+=no;
            pq.pop();
            pq.push((no+2)/3);
        }
        return sum;
    }
};