class Solution {
public:
    int reverse(int x) {
        int no=abs(x);
        int rev=0;
        while(no){
            int rem=no%10;
            if(rev>(INT_MAX-rem)/10){
                return 0;
            }
            rev=rev*10+rem;
            no/=10;
        }
        return (x<0)?rev*-1:rev;
    }
};