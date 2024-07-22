class Solution {
public:
    static bool comp(pair<string,int> &a,pair<string,int>& b){
        return a.second>b.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<pair<string,int>>coder;
        for(int i=0;i<n;i++){
            coder.push_back({names[i],heights[i]});
        }
        sort(coder.begin(),coder.end(),comp);
        vector<string>ans;
        for(int i=0;i<n;i++){
            ans.push_back(coder[i].first);
        }
        return ans;
    }
};