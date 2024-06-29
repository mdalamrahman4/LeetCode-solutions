class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)  q.push(i);
        }
        vector<set<int>>ans(n);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int top=q.front();
                for(auto &it:adj[top]){
                    indegree[it]--;
                    ans[it].insert(top);
                    if(indegree[it]==0) q.push(it);
                    for(auto &j:ans[top]){
                        ans[it].insert(j);
                    }
                }
                q.pop();
            }
        }
        vector<vector<int>>res(n);
        for(int i=0; i<n; i++)
        {
            for(auto j : ans[i])
            {
                res[i].push_back(j);
            }
        }
        return res;
    }
};