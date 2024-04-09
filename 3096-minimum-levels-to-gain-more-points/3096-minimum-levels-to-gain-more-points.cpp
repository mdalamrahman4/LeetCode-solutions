class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        int dan=0,bob=0;
        for(int i=0;i<n;i++){
            if(possible[i]==0){
                possible[i]=-1;
            }   
        }
        int ans=accumulate(possible.begin(),possible.end(),0);
        for(int i=0;i<n-1;i++){
            bob+=possible[i];
            if(bob>(ans-bob)){
                return i+1;
            }
        }
        return -1;
    }
};