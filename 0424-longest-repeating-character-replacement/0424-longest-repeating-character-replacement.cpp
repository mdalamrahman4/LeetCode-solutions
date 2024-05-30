class Solution {
public:
    int characterReplacement(string s, int k) {
        int mxlen=0;
        vector<int>freq(26,0);
        int mxfreq=0;
        int l=0,r=0;
        while(r<s.size()){
            freq[s[r]-'A']++;
            mxfreq=max(freq[s[r]-'A'],mxfreq);
            while((r-l+1)-mxfreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-mxfreq<=k){
                mxlen=max(mxlen,r-l+1);
            }
            r++;
        }
        return mxlen;
    }
};