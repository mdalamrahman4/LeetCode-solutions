class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)    return {};
        vector<int>ans(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        int cnt=1;
        ans[pq.top().second]=cnt;
        int prev=pq.top().first;
        pq.pop();
        while(!pq.empty()){
            if(prev!=pq.top().first)  cnt++;
            ans[pq.top().second]=cnt;
            prev=pq.top().first;
            pq.pop();
        }
        return ans;
    }
};