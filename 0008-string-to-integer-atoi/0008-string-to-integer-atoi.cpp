class Solution {
public:
    int myAtoi(string s) {
        long ans=0;
        int i=0,sign=1;
        while(i<s.length() && s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<s.length()){
            if(isdigit(s[i])){
                ans=ans*10+(s[i]-'0');
                if(ans>INT_MAX && sign==1){
                    return INT_MAX;
                }
                else if(ans>INT_MAX && sign==-1){
                    return INT_MIN;
                }
                i++;
            }
            else{
                return ans*sign;
            }
        }
        return ans*sign;
    }
};