class Solution {
public:
    int pivotInteger(int n) {
        int lsum = 0;
        int total = (n * (n + 1)) / 2;
        int i = 1, j = n;
        while (i <= j) {
            int mid = (i + j) / 2;
            int midsum = (mid * (mid + 1)) / 2;
            if (total - midsum+mid == midsum) 
                return mid;
            else if (total - midsum+mid > midsum) 
                i = mid + 1;
            else 
                j = mid - 1;
        }
        return -1;
    }
};
