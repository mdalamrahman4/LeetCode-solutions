class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int count=0;
        for(int i=1;i<n-1;i++){
            int smallonleft=0,largeonright=0,largeonleft=0,smallonright=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]){
                    smallonleft++;
                }
                else{
                    largeonleft++;
                }
            }
            for(int j=n-1;j>i;j--){
                if(rating[j]<rating[i]){
                    smallonright++;
                }
                else{
                    largeonright++;
                }
            }
            count+=(smallonleft*largeonright+largeonleft*smallonright);
        }
        return count;
    }
};