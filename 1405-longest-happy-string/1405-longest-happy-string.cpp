class Solution {
public:
    typedef pair<int,char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P,vector<P>>pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string res="";
        while(!pq.empty()){
            int currcnt=pq.top().first;
            int currchar=pq.top().second;
            pq.pop();
            if(res.size()>=2 && res[res.size()-1]==currchar && res[res.size()-2]==currchar){
                if(pq.empty())  break;
                int nxtcnt=pq.top().first;
                int nxtchar=pq.top().second;
                pq.pop();
                res.push_back(nxtchar);
                nxtcnt--;
                if(nxtcnt>0){
                    pq.push({nxtcnt,nxtchar});
                }
            }
            else{
                currcnt--;
                res.push_back(currchar);
            }
            if(currcnt>0){
                pq.push({currcnt,currchar});
            }
        }
        return res;
    }
};