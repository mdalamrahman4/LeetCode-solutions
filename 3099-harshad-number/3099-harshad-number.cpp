class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        string s=to_string(x);
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=(s[i]-'0');
        }
        return (x%sum==0?sum:-1);
    }
};