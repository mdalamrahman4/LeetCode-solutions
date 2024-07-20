class Solution {
public:
    string losingPlayer(int x, int y) {
        string pl1="Alice",pl2="Bob";
        bool flag=true;
        while(x>=1 && y>=4){
            x--;
            y-=4;
            flag=!flag;
        }
        return flag?"Bob":"Alice";
    }
};