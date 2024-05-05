class Solution {
public:
    bool isValid(string word) {
        bool vow=false,con=false;
        int cnt=0;
        for(char &ch:word){
            cnt++;
            if(!isalnum(ch))    return false;
            else if(isalpha(ch)){ 
                if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || 
                  ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')  {
                    vow=true;
                }
                else{
                    con=true;
                }
            }
        }
        return (cnt>=3 && vow && con);
    }
};