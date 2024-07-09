class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int st=customers[0][0];
        long long cnt=0,n=customers.size();
        for(int i=0;i<n;i++){
            st=max(st,customers[i][0]);
            int ft=st+customers[i][1];
            cnt+=(ft-customers[i][0]);
            st=ft;
        }
        return (cnt/(n*1.0));
    }
};