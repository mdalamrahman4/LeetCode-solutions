class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int st=customers[0][0];
        double cnt=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            st=max(st,customers[i][0]);
            int ft=st+customers[i][1];
            cnt+=(ft-customers[i][0]);
            st=ft;
        }
        return cnt/n;
    }
};