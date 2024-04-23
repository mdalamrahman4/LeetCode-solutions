class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>str(128,0);
        int mx=0;
        int left=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            left=max(left,str[c]);
            str[c]=i+1;
            mx=max(mx,i-left+1);
        }
        return mx;
    }
};