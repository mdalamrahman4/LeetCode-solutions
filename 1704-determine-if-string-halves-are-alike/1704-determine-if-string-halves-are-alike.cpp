class Solution {
public:
    int isvowel(char ch)
    {
        string str="aeiouAEIOU";
        return (str.find(ch)!=string::npos);
    }
    bool halvesAreAlike(string s) {
        int c1=0,c2=0;
        int n=s.length()/2;
        for(int i=0;i<n;i++)
        {
            if(isvowel(s[i])) c1++;
        }
        for(int i=n;i<s.length();i++)
        {
            if(isvowel(s[i])) c2++;
        }
        return (c1==c2);
    }
};