class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chr(128, 0);  
        for (char c : t) {
            chr[c]++;
        }

        int start = 0, end = 0, cnt = t.size(), minlen = INT_MAX, mnstart = 0;

        while (end < s.size()) {
            if (chr[s[end]] > 0) cnt--;
            chr[s[end]]--;
            end++;

            while (cnt == 0) {
                if (end - start < minlen) {
                    minlen = end - start;
                    mnstart = start;
                }
                chr[s[start]]++;
                if (chr[s[start]] > 0) cnt++;
                start++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(mnstart, minlen);
    }
};
