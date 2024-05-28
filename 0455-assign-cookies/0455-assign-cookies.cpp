class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int chilren=0,cookie=0;
        while(chilren<g.size() && cookie<s.size()){
            if(g[chilren]<=s[cookie]) {
                chilren++;
                cookie++;
            }  
            else cookie++;
        }
        return chilren;
    }
};