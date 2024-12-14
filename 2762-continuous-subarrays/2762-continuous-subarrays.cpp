class Solution {
public:
    typedef pair<int,int> p;
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        long long count=0;
        priority_queue<p>mx;
        priority_queue<p,vector<p>,greater<p>>mn;
        while(j<n){
            mx.push({nums[j],j});
            mn.push({nums[j],j});
            while(abs(mx.top().first-mn.top().first)>2){
                i++;
                while(!mx.empty() && mx.top().second<i){
                    mx.pop();
                }
                while(!mn.empty() && mn.top().second<i){
                    mn.pop();
                }
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
};