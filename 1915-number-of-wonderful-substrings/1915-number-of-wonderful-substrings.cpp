class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int bit=0;
        for(int i=0;i<word.length();i++)
        {
            bit=bit^(1<<(word[i]-'a'));
            ans=ans+mp[bit];  // if bit pattern repeats itself this means all characters have 
            // even occurence
            for(int j=0;j<10;j++)
            {
                ans=ans+mp[bit^(1<<j)]; // for odd occurence just flip one bit out of 10
            }
            mp[bit]++;
        }
        return ans;
    }
};