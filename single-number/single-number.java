class Solution {
    public int singleNumber(int[] nums) {
        int xr=0;
        for(int it:nums)    xr^=it;
        return xr;
    }
}