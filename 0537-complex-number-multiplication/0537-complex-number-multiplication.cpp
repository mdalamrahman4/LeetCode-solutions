class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        stringstream aa(num1),bb(num2),ans;
        int ra,rb,ca,cb;
        char buff;
        aa>>ra>>buff>>ca>>buff;
        bb>>rb>>buff>>cb>>buff;
        ans<<ra*rb-ca*cb<<'+'<<ra*cb+rb*ca<<'i';
        return ans.str();
    }
};