class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int>mp;
        for(auto &it:candyType){
            mp[it]++;
        }
        int n=candyType.size();
        int mx=n/2;
        int all=mp.size();
        return min(all,mx);
    }
};