class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &it:arr){
            mp[it]++;
        }
        for(auto &it:mp){
            pq.push(it.second);
        }
        while(k>0){
            k-=pq.top();
            if(k>=0)    pq.pop();
            
        }
        return pq.size();
    }
};