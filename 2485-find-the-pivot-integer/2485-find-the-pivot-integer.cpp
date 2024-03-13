class Solution {
public:
    int pivotInteger(int n) {
        int lsum=0;
        int total=(n*(n+1))/2;
        for(int i=1;i<=n;i++){
            lsum+=i;
            if(total-lsum+i==lsum)  return i;
        }
        return -1;
    }
};