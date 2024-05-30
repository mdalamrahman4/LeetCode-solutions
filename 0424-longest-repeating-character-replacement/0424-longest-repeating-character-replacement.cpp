class Solution {
public:
    int characterReplacement(string s, int k) {
        int mxlen=0;
        for(int i=0;i<s.size();i++){
            vector<int>freq(26,0);
            int mxfreq=0;
            for(int j=i;j<s.size();j++){
                freq[s[j]-'A']++;
                mxfreq=max(mxfreq,freq[s[j]-'A']);
                int diff=(j-i+1)-mxfreq;
                if(diff<=k){
                    mxlen=max(mxlen,j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return mxlen;
    }
};