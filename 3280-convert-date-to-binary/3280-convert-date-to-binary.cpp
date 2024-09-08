class Solution {
public:
    string convert(int num){
        string ans="";
        while(num){
            ans+=to_string(num%2);
            num/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string convertDateToBinary(string date) {
        stringstream ss(date);
        int yy,mm,dd;
        char c;
        ss>>yy>>c>>mm>>c>>dd;
        string ans=convert(yy)+"-"+convert(mm)+"-"+convert(dd);
        return ans;
    }
};