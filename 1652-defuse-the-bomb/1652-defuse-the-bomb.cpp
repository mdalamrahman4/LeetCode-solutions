class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n,0);
        if(k==0)    return ans;
        int i,j;
        if(k<0){
            i=n-abs(k);
            j=n-1;
        }
        else{
            i=1;
            j=k;
        }
        int windowsum=0;
        for(int k=i;k<=j;k++){
            windowsum+=code[k];
        }
        for(int k=0;k<n;k++){
            ans[k]=windowsum;
            windowsum-=code[i%n];
            i++;
            windowsum+=code[(j+1)%n];
            j++;
        }
        return ans;
    }
};