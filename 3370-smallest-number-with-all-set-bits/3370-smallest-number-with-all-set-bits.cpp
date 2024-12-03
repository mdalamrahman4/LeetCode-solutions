class Solution {
public:
    int smallestNumber(int n) {
        for(int i=1;i<=n;i++){
            if((1<<i)>n){
                return (1<<i)-1;
            }
        }
        return -1;
    }
};