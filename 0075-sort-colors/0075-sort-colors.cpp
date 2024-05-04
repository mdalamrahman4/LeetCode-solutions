class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        for(auto &it:nums){
            (it!=2)?((it==1)?one++:zero++):two++;
        }
        int i=0;
        while(zero--){
            nums[i++]=0;
        }
        while(one--){
            nums[i++]=1;
        }
        while(two--){
            nums[i++]=2;
        }
    }
};