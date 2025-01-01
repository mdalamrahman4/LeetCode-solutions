class Solution {
public:
    int maxScore(string s) {
        int rightones=count(s.begin(),s.end(),'1');
        int leftzeroes=0;
        int mx=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0')   leftzeroes++;
            else rightones--;
            mx=max(mx,leftzeroes+rightones);
        }
        return mx;
    }
};