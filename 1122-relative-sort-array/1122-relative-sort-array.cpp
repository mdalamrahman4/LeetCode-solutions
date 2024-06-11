class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        vector<int>rem;
        int t=0;
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]>0){
                res.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        for(auto &it:mp){
            while(it.second>0){
                rem.push_back(it.first);
                it.second--;
            }
        }
        sort(rem.begin(),rem.end());
        res.insert(res.end(),rem.begin(),rem.end());
        return res;
    }
};