class Solution {
public:
    typedef pair<double,int> p;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;
        vector<double>result(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<p>pq;
        result[start_node]=1;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            int currnode=pq.top().second;
            double currprob=pq.top().first;
            pq.pop();
            for(auto &temp:adj[currnode]){
                if(result[temp.first]<currprob*temp.second){
                    result[temp.first]=currprob*temp.second;
                    pq.push({result[temp.first],temp.first});
                }
            }
        }
        return result[end_node];
    }
};