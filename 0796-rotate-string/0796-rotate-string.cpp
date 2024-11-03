class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())   return false;
        string conc=goal+goal;
        return conc.find(s)!=string::npos;
    }
};