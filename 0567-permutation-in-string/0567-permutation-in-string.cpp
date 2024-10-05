class Solution {
public:
    bool compare(vector<int>&freq,vector<int>&tmpfreq){
        for(int i=0;i<26;i++){
            if(freq[i]!=tmpfreq[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        vector<int>freq(26,0);
        vector<int>tmpfreq(26,0);
        for(char it:s1) freq[it-'a']++;
        for(int i=0;i<n;i++){
            tmpfreq[s2[i]-'a']++;
            if(i==m-1 && compare(freq,tmpfreq))    return true;
            if(i>=m){
                tmpfreq[s2[i-m]-'a']--;
                if(compare(freq,tmpfreq))   return true;
            }
        }
        return false;
    }
};