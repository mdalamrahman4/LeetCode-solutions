class Solution {
public:
    int maximumSwap(int num) {
        string no=to_string(num);
        int n=no.size();
        vector<int>mxno(n);
        mxno[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(no[i]>no[mxno[i+1]]){
                mxno[i]=i;
            }
            else{
                mxno[i]=mxno[i+1];
            }
        }
        for(int i=0;i<n;i++){
            if(no[i]<no[mxno[i]]){
                swap(no[i],no[mxno[i]]);
                return stoi(no);
            }
        }
        return num;
    }
};