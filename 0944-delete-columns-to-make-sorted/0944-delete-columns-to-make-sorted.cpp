class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),k=strs[0].size();
        int count=0;
        for(int i=0;i<k;i++){
            for(int j=1;j<n;j++){
                if(strs[j-1][i]>strs[j][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};