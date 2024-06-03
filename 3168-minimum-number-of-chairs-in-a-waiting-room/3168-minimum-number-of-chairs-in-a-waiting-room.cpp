class Solution {
public:
    int minimumChairs(string s) {
        int chmax=0,entry=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E')   entry++;
            else if(s[i]=='L')  entry--;
            chmax=max(chmax,entry);
        }
        return chmax;
    }
};