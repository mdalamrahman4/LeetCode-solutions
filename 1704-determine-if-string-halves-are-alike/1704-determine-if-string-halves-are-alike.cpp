class Solution {
public:
    bool halvesAreAlike(string s) {
        int c=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            s[i]=tolower(s[i]);
            if(i<n/2)
            {
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                {
                    c++;
                }
            }
            else
            {
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                {
                    c--;
                }
            }
        }
        return (c==0);
    }
};