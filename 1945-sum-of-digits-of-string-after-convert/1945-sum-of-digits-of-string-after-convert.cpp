class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            int val=(s[i]-'a'+1);
            sum+=(val<10)?val:(val%10+val/10);
        }
        k--;
        while(k-- && sum>9){
            int copy=sum;
            int ans=0;
            while(copy!=0){
                ans+=(copy%10);
                copy/=10;
            }
            sum=ans;
        }
        return sum;
    }
};