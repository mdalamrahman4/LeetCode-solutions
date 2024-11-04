class Solution {
public:
    bool isBalanced(string num) {
        int osum=0;
        bool oddy=true;
        for(auto it:num){
            if(oddy)    osum+=(it-'0');
            else    osum-=(it-'0');
            oddy=!oddy;
        }
        return (osum==0);
    }
};