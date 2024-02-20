class Solution {
public:
    int missingNumber(vector<int>& array) { // n is the upper bound of the range
    int n=array.size()+1, xoro;
    if ((n-1) % 4 == 0)
        xoro = n-1;
    else if ((n-1) % 4 == 1)
        xoro = 1;
    else if ((n-1) % 4 == 2)
        xoro = n;
    else
        xoro = 0;
    for (int i = 0; i < n-1; i++) { // loop until n-1
        xoro = xoro ^ array[i];
    }
    return xoro;
}

};