class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(124,0);
        for(char &ch:s){
            freq[ch]++;
        }
        sort(s.begin(),s.end(),[&](char a,char b){
            return freq[a]>freq[b] || (freq[a]==freq[b] && a<b);
        });
        return s;
    }
};