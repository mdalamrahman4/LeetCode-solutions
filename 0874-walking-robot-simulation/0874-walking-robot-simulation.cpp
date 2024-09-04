class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(vector<int>&it:obstacles){
            string temp=to_string(it[0])+"@"+to_string(it[1]);
            st.insert(temp);
        }
        pair<int,int>dir={0,1};
        int x=0,y=0;
        int mx=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-2){
                dir={-dir.second,dir.first};
            }
            else if(commands[i]==-1){
                dir={dir.second,-dir.first};
            }
            else{
                for(int step=0;step<commands[i];step++){
                    int newx=x+dir.first;
                    int newy=y+dir.second;
                    string key=to_string(newx)+"@"+to_string(newy);
                    if(st.find(key)!=st.end()){
                        break;
                    }
                    x=newx;
                    y=newy;
                }
            }
            mx=max(mx,x*x+y*y);
        }
        return mx;
    }
};