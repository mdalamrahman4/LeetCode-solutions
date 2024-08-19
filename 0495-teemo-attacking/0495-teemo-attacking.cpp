class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int cnt=0,prev=-1;
        for(int i=0;i<timeSeries.size();i++){
            if(prev==-1 || prev<timeSeries[i]){
                cnt+=duration;
                prev=timeSeries[i]+duration;
            }
            else if(prev>=timeSeries[i]){
                cnt+=(duration-(prev-timeSeries[i]));
                prev=timeSeries[i]+duration;
            }
        }
        return cnt;
    }
};