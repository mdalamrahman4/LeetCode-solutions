class Solution {
public:
    bool check(int n){
        if(n==0)    return true;
        for(int i=1;i<=n;i++){
            if(n%i==0)  return !check(n-i);
        }
        return false;
    }
    bool divisorGame(int n) {
        return check(n);
    }
};