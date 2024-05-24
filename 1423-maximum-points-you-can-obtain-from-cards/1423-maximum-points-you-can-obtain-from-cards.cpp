class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int rsum=0,r=cardPoints.size()-1;
        int msum=0;
        for(int i=k-1;i>=0;i--){
            msum=max(msum,lsum+rsum);
            lsum-=cardPoints[i];
            rsum+=cardPoints[r--];
        }
        msum=max(msum,lsum+rsum);
        return msum;
    }
};