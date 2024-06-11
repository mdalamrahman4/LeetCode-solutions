class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>mp(1001,0);
        vector<int>res;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        int t=0;
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]>0){
                res.push_back(arr2[i]);
                mp[arr2[i]]--;
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