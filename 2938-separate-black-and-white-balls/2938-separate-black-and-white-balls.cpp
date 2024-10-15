class Solution {
public:
    long long minimumSteps(string s) {
        long long white=0,black=0;
        for(auto &it:s){
            if(it=='1')   white++;
            else    black+=white;
        }
        return black;
    }
};