class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>lst(3,-1);
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            lst[s[i]-'a']=i;
            if(lst[0]!=-1 && lst[1]!=-1 && lst[2]!=-1){
                cnt+=(1+min(lst[0],min(lst[1],lst[2])));
            }
        }
        return cnt;
    }
};