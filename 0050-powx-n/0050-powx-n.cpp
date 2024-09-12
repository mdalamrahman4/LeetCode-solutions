class Solution {
public:
    double myPow(double x, int n) {
        double powered=1.0;
        long nn=n;
        nn=abs(nn);
        while(nn>0){
            if(nn%2==0)
            {
                x*=x;
                nn/=2;
            }    
            else{
                powered*=x;
                nn--;
            }
        }
        if(n<0) powered=((double)(1.0)/(double)(powered));
        return powered;
    }
};