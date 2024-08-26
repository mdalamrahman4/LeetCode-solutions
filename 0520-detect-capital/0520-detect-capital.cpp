class Solution {
public:
    bool detectCapitalUse(string word) {
        int cntcapital=0,n=word.size();
        for(char &it:word)  if(isupper(it)) cntcapital++;
        return (cntcapital==0 || cntcapital==n || (isupper(word[0]) && cntcapital==1));
    }
};