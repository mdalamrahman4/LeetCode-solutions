class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())  return false;
        vector<int>w1(26,0),w2(26,0),w3(26,0),w4(26,0);
        for(int i=0;i<word1.size();i++){
            w1[word1[i]-'a']++;
            w3[word1[i]-'a']=1;
            w2[word2[i]-'a']++;
            w4[word2[i]-'a']=1;
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        return w1==w2 && w3==w4;
    }
};