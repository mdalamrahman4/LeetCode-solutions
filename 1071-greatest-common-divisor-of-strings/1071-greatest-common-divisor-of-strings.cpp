class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)    return "";
        int n=str1.size(),m=str2.size();
        n=__gcd(n,m);
        return str1.substr(0,n);
    }
};