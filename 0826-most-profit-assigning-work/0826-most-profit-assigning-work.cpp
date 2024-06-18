class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)     {
        int n=worker.size();
        sort(worker.begin(),worker.end());
        vector<pair<int,int>>par;
        for(int i=0;i<n;i++){
            par.push_back({difficulty[i],profit[i]});
        }
        int mxprofit=0,tmpprofit=0;
        sort(par.begin(),par.end());
        for(int i=0;i<n;i++){
            int j=0;
            while(j<n && par[j].first<=worker[i]){
                tmpprofit=max(par[j].second,tmpprofit);
                j++;
            }
            if(j>0 && par[j-1].first<=worker[i]){
                mxprofit=mxprofit+tmpprofit;
            }
        }
        return mxprofit;
    }
};