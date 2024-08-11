class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0,j=0;
        int cnt=0;
        for(auto &it:commands){
            if(it=="DOWN")  cnt+=n;
            else if(it=="UP")   cnt-=n;
            else if(it=="RIGHT")    cnt++;
            else cnt--;  
        }
        return cnt;
    }
};