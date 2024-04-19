class Solution {
public:
    int alternateDigitSum(int n) {
        int dif=log10(n)+1;
        int sum=0;
        bool sign;
        if(dif%2==0){
            sign=false;
        }
        else{
            sign=true;
        }
        while(n){
                if(sign==false){
                    sum-=(n%10);
                }
                else{
                    sum+=n%10;
                }
                n/=10;
                sign=!sign;
            }
        return sum;
    }
};