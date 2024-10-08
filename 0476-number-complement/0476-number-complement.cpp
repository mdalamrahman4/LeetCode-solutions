class Solution {
public:
    int findComplement(int num) {
        int cnt=log2(num)+1;
        int mask=(long)(1<<cnt)-1;
        return mask^num;
    }
};