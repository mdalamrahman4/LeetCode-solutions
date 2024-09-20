class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        if(n==0)    return s;
        int left=0;
        for(int right=n-1;right>=0;right--){
            if(s[right]==s[left])   left++;
        }
        if(left==n) return s;
        string nps=s.substr(left);
        string reversenps=string(nps.rbegin(),nps.rend());
        return reversenps+shortestPalindrome(s.substr(0,left))+nps;
    }
};