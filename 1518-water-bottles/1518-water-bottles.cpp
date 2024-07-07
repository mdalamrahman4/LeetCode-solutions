class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count=numBottles;
        while(numBottles>=numExchange){
            int rem=(numBottles%numExchange);
            numBottles/=numExchange;
            count+=numBottles;
            numBottles+=rem;
        }
        return count;
    }
};