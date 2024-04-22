class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>cnt(26,0);
        for(int i=0;i<word.size();i++){
            if(word[i]>=97) {
                if(cnt[word[i]-'a']==0){
                    cnt[word[i]-'a']=1;
                }
                else if(cnt[word[i]-'a']==5){
                    cnt[word[i]-'a']=-1;
                }
            }
            else{
                if(cnt[word[i]-'A']==0){
                    cnt[word[i]-'A']=2;
                }
                else if(cnt[word[i]-'A']==1){
                    cnt[word[i]-'A']=5;
                }
            }
        }
        int c=0;
        for(int i=0;i<26;i++){
            if(cnt[i]==5){
                c++;
            }
        }
        return c;
    }
};