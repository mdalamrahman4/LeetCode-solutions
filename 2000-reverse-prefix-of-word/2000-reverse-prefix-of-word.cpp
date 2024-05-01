class Solution {
public:
    string reversePrefix(string word, char ch) {
        int ind=0;
        while(word[ind]!=ch && ind<word.size()){
            ind++;
        }
        if(ind>=word.size())    return word;
        reverse(word.begin(),word.begin()+ind+1);
        return word;
    }
};