class Solution {
public:
    int mySqrt(int x) {
        if(x==0)    return 0;
        int i=1,j=x;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(mid==x/mid){
                return mid;
            }
            else if(mid<x/mid){
                i=mid+1;
            }
            else j=mid-1;
        }
        return j;
    }
};