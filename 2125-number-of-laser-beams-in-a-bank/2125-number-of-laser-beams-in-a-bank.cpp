class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int ans=0;
        int prev=0;
        for(int i=0;i<n;i++){
                string s=bank[i];
              int c=count(s.begin(),s.end(),'1');
                   ans+=c*prev;
                   if(c!=0){
                     prev=c;}
         }
         
                return ans;
   }
};