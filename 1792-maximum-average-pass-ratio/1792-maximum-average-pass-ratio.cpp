class Solution {
public:
    typedef pair<double,int> p;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<p>pq;
        int cnt=0;
        for(auto &it:classes){
            double currpr=(double(it[0])/it[1]);
            double newpr=((double(it[0]+1))/(it[1]+1));
            double change=newpr-currpr;
            pq.push({change,cnt++});
        }
        while(extraStudents--){
            double currchange=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            classes[ind][0]++;
            classes[ind][1]++;
            double currpr=(double(classes[ind][0])/classes[ind][1]);
            double newpr=((double(classes[ind][0]+1))/(classes[ind][1]+1));
            double change=newpr-currpr;
            pq.push({change,ind});
        }
        double res=0;
        for(auto it:classes){
            res+=(double(it[0])/it[1]);
        }
        return res/n;
    }
};