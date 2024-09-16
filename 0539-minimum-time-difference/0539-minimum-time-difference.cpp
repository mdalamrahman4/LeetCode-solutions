class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int>minutes(n);
        for(int i=0;i<n;i++){
            string timer=timePoints[i];
            int hour=stoi(timer.substr(0,2));
            int min=stoi(timer.substr(3,4));
            minutes[i]=hour*60+min;
        }
        int mx=1e9;
        sort(minutes.begin(),minutes.end());
        for(int i=1;i<n;i++){
            mx=min(mx,minutes[i]-minutes[i-1]);
        }
        return min(mx,(1440-minutes[n-1])+minutes[0]);
    }
};