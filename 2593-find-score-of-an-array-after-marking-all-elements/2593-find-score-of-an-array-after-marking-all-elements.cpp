class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        int marked=0;
        vector<bool>mark(n,false);
        long long score=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(marked<n && !pq.empty()){
            int tp=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(!mark[ind]){
                mark[ind]=true;
                marked++;
                score+=tp;
                if(ind>0 && !mark[ind-1]){
                mark[ind-1]=true;
                marked++;
            }
            if(ind<n-1 && !mark[ind+1]){
                mark[ind+1]=true;
                marked++;
            }
            }
        }
        return score;
    }
};