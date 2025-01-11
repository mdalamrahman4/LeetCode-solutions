class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>freq(26,0);
        for(char c:s)   freq[c-'a']++;
        int odd = 0;
        for (int i=0;i<26;i++) {
            if (freq[i]%2 == 1) {
                odd++;
            }
        }
        if (k >= odd && k <= s.size()) {
            return true;
        } else {
            return false;
        }
    }
};