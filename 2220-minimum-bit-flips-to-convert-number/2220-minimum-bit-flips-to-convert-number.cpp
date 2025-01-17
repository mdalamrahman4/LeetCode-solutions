class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xr=start^goal;
        int cnt=0;
        while(xr){
            if(xr&1)cnt++;
            xr=xr>>1;
        }
        return cnt;
    }
};