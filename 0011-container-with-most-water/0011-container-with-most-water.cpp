class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int s=0;
        int e=height.size()-1;
        while(s<e){
            ans=max((e-s)*min(height[s],height[e]),ans);
            if(height[s]<height[e]) s++;
            else    e--;
        }
        return ans;
    }
};