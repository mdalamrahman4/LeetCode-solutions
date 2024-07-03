class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twenty=0;
        for(auto &it:bills){
            if(it==5){
                five++;
            }
            else if(it==10){
                ten++;
                if(five==0) return false;
                five--;
            }
            else{
                if(five>0 && ten>0) {
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};