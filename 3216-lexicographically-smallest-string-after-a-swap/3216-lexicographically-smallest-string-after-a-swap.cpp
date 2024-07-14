class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0;i<s.size()-1;i++){
            int curr=s[i]-'0',nxt=s[i+1]-'0';
            if((curr%2==0 && nxt%2==0)|| (curr%2==1 && nxt%2==1))
            {
                if(curr>nxt){
                    swap(s[i],s[i+1]);
                    break;
                }
            }
        }
        return s;
    }
};