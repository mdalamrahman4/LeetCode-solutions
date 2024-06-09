class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int rem=k%n;
        int div=k/n;
        if(div%2==0){
            return rem;
        }
        else{
            return (n-rem);
        }
    }
};