class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        long long sum=0;
        while(k--){
            int no=pq.top();
            sum+=no;
            no=ceil(no/3.0);
            pq.pop();
            pq.push(no);
        }
        return sum;
    }
};