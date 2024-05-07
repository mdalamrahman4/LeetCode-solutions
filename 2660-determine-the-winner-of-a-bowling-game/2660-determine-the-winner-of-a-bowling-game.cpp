class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int sum1=0,sum2=0;
        int prev1=0,prev2=0;
        for(auto &it:player1){
            if(prev1==10 || prev2==10)  sum1+=(2*it);
            else sum1+=it;
            prev2=prev1;
            prev1=it;
        }
        prev1=prev2=0;
        for(auto &it:player2){
            if(prev1==10 || prev2==10)  sum2+=(2*it);
            else sum2+=it;
            prev2=prev1;
            prev1=it;
        }
        if(sum1>sum2)   return 1;
        if(sum2>sum1)   return 2;
        return 0;
    }
};