class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int totalsum=accumulate(rolls.begin(),rolls.end(),0);
        int t=rolls.size();
        int missingsum=(t+n)*mean-totalsum;
        if(missingsum<n || missingsum>6*n)  return {};
        int part=missingsum/n;
        int rem=missingsum%n;
        vector<int>ans(n,part);
        for(int i=0;i<rem;i++){
            ans[i]++;
        }
        return ans;
    }
};