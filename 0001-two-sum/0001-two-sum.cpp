class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<pair<int,int>>p;
        for(int i=0;i<=j;i++){
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end());
        while(i<j){
            if(p[i].first+p[j].first==target) return {p[i].second,p[j].second};
            else if(p[i].first+p[j].first<target) i++;
            else    j--;
        }
        return {-1,-1};
    }
};