class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int n=citations.size();
        int ans=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]<i+1){
                break;
            }
            ans=i+1;
        }
        return ans;
    }
};