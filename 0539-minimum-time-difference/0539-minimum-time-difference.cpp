class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int>minutes(n);
        vector<int>count(1440,0);
        for(int i=0;i<n;i++){
            string timer=timePoints[i];
            int hour=stoi(timer.substr(0,2));
            int min=stoi(timer.substr(3,4));
            minutes[i]=hour*60+min;
            count[minutes[i]]++;
        }
        int x=0;
        for(int i=0;i<1440;i++){
            while(count[i]>0){
                minutes[x++]=i;
                count[i]--;
            }
        }
        int mx=1e9;
        for(int i=1;i<n;i++){
            mx=min(mx,minutes[i]-minutes[i-1]);
        }
        return min(mx,(1440-minutes[n-1])+minutes[0]);
    }
};