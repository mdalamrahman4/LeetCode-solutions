class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(char &it:columnTitle){
            int rem=it-'A'+1;
            ans=ans*26+rem;
        }
        return ans;
    }
};