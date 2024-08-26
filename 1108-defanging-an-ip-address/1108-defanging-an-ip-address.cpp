class Solution {
public:
    string defangIPaddr(string address) {
        stringstream ss(address);
        string result="";
        string token;
        while(getline(ss,token,'.')){
            result+=token+"[.]";
        }
        return result.substr(0,result.length()-3);
    }
};