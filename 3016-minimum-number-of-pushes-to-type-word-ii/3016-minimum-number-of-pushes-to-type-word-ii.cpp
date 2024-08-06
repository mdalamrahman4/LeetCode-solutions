class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        int cnt=0,ans=0;
        sort(freq.rbegin(),freq.rend());
        for(int i=0;i<26;i++){
            if(freq[i]==0)  break;
            if(cnt<=7)  {
                ans+=(freq[i]);
            }
            else if(cnt<=15)    ans+=(freq[i]*2);
            else if(cnt<=23)    ans+=(freq[i]*3);
            else    ans+=(freq[i]*4);
            cnt++;
        }
        return ans;
    }
};