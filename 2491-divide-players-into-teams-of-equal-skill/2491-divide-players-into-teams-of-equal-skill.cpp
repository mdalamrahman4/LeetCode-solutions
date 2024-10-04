class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans=0;
        int low=0,high=skill.size()-1;
        long long sum=skill[0]+skill[high];
        while(low<=high){
            long long currsum=skill[low]+skill[high];
            if(sum!=currsum)    return -1;
            ans=ans+(skill[low]*skill[high]);
            low++;
            high--;
        }
        return ans;
    }
};