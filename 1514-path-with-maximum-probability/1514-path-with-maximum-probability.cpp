class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<int>vis(n,0);
        priority_queue<pair<double,int>>pq;
        pq.push({double(1.0),start});
        vector<double>mx(n,(double)0.0);
        mx[start]=1.0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            double proba=it.first;
            int node=it.second;
            if(!vis[node])
            {
                vis[node]=1;
                for(auto &it:adj[node])
                {
                    double probb=it.second;
                    int adjNode=it.first;
                    if(proba*probb>mx[adjNode])
                    {
                        mx[adjNode]=proba*probb;
                        pq.push({mx[adjNode],adjNode});
                    }
                }
            }
        }
        return mx[end];
    }
};