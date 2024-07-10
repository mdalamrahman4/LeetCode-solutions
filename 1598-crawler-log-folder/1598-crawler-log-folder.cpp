class Solution {
public:
    int minOperations(vector<string>& logs) {
        int start=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){
                if(start!=0){
                    start--;
                }
            }
            else if(logs[i]=="./"){
                continue;
            }
            else{
                start++;
            }
        }
        return start;
    }
};