class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=s.size();
        vector<int>freq(128,-1);
        int mxlen=0;
        while(r<n){
            if(freq[s[r]]>=l){
                l=freq[s[r]]+1;
            }
            int len=r-l+1;
            mxlen=max(len,mxlen);
            freq[s[r]]=r;
            r++;
        }
        return mxlen;
    }
};