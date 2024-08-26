class Solution {
public:
    bool iscapital(string word,int i,int j){
        for(int x=i;x<=j;x++){
            if(!isupper(word[x]))   return false;
        }
        return true;
    }
    bool notcapital(string word,int i,int j){
        for(int x=i;x<=j;x++){
            if(!islower(word[x]))   return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        int n=word.size();
        return (iscapital(word,0,n-1) || notcapital(word,0,n-1) || notcapital(word,1,n-1));
    }
};