class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0,scnt=0;
        for(auto it:s){
            if(it==')'){
                if(scnt<=0)  cnt++;
                else scnt--;
            }
            else scnt++;
        }
        return cnt+scnt;
    }
};