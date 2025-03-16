class Solution {
public:
    typedef long long ll;
    bool isposs(vector<int>&ranks,ll mid,int cars){
        ll cnt=0;
        for(int i=0;i<ranks.size();i++){
            int c_time=sqrt((mid*1.0)/ranks[i]);
            cnt+=c_time;
        }
        return cnt>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int maxr=*max_element(ranks.begin(),ranks.end());
        ll low=1,high=1LL*maxr*cars*cars;
        ll res=-1;
        while(low<=high){
            ll mid=(low+high)/2;
            if(isposs(ranks,mid,cars)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};