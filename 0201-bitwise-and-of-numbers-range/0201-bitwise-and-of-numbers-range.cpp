class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int bit=0;
        while(left!=right){
            bit++;
            left>>=1;
            right>>=1;
        }
        return left<<bit;
    }
};