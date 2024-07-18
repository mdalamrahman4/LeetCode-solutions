class Solution {
public:
    int trap(vector<int>& height) {
        int total=0,lmax=0,rmax=0,l=0,r=height.size()-1;
        while(l<r){
            if(height[l]<=height[r]){
                lmax=max(lmax,height[l]);
                total+=lmax-height[l];
                l++;
            }
            else{
                rmax=max(rmax,height[r]);
                total+=rmax-height[r];
                r--;
            }
        }
        return total;
    }
};