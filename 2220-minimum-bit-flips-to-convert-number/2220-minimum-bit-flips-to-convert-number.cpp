class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xr=start^goal;
        int cnt=0;
        while(xr){
            cnt+=(xr&1);
            xr=xr>>1;
        }
        return cnt;
    }
};