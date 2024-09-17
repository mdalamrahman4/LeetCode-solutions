class Solution {
public:
    long long hours(vector<int>&piles,int mid){
        long long total=0;
        for(auto &it:piles){
            total+=ceil((double)it/(double)mid);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            long long totalhrs=hours(piles,mid);
            if(totalhrs<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};