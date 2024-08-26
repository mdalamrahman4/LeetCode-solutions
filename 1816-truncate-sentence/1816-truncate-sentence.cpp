class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        int cnt=0;
        string token="",result="";
        while(ss>>token){
            result+=token+" ";
            if(++cnt==k)  break;
        }
        return result.substr(0,result.length()-1);
    }
};