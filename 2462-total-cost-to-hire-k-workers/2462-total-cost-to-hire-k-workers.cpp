class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        int n=costs.size();
        priority_queue <int, vector<int>, greater<int>> pq1,pq2;
        int i=0,j=n-1;
        while(k-- ){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size()<candidates && j>=i){
                pq2.push(costs[j]);
                j--;
            }
            if(pq1.size()>0 && (pq2.empty() || pq1.top()<=pq2.top())) {
                ans+=pq1.top();
                pq1.pop();
            }
            else if(pq2.size()>0){
                ans+=pq2.top();
                pq2.pop();
            }
        }
        return ans;
    }
};