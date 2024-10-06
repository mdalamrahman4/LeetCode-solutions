class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string>v1,v2;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string entry;
        while(ss1>>entry){
            v1.push_back(entry);
        }
        while(ss2>>entry){
            v2.push_back(entry);
        }
        int i1=0,j1=0,i2=v1.size()-1,j2=v2.size()-1;
        while(i1<=i2 && j1<=j2){
            if(v1[i1]==v2[j1]){
                i1++;
                j1++;
            }
            else if(v1[i2]==v2[j2]){
                i2--;
                j2--;
            }
            else return false;
        }
        return true;
    }
};