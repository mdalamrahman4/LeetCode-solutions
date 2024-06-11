class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>mp(1001,0);
        vector<int>res;
        for(auto &it:arr1){
            mp[it]++;
        }
        for(auto &it:arr2){
            while(mp[it]>0){
                res.push_back(it);
                mp[it]--;
            }
        }
        for(int i=0;i<1001;i++){
            while(mp[i]>0){
                res.push_back(i);
                mp[i]--;
            }
        }
        return res;
    }
};