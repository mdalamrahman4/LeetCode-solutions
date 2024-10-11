class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        int arrivefriend=times[targetFriend][0];
        sort(times.begin(),times.end());
        vector<int>chair(n,-1);
        for(vector<int>&time:times){
            int arrive=time[0];
            int dep=time[1];
            for(int i=0;i<n;i++){
                if(chair[i]<=arrive){
                    chair[i]=dep;
                    if(arrive==arrivefriend){
                        return i;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};