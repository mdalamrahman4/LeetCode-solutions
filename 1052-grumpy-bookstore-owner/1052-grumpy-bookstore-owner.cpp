class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied=0,window=0,mxw=0;
        int l=0;
        for(int r=0;r<customers.size();r++){
            if(grumpy[r]){
                window+=customers[r];
            }
            else{
                satisfied+=customers[r];
            }
            if(r-l+1>minutes){
                if(grumpy[l]){
                    window-=customers[l];
                }
                ++l;
            }
            mxw=max(mxw,window);
        }
        return satisfied+mxw;
    }
};