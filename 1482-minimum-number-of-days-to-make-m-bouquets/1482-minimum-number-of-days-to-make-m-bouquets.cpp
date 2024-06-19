class Solution {
public:
    bool isPossible(vector<int>& bloomDay,int mid,int m,int k)
    {
        int cnt=0,bl=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)
            {
                cnt++;
            }
            else
            {
                bl+=(cnt/k);
                cnt=0;
            }
        }
        bl+=(cnt/k);
        return bl>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=(long long)m *(long long)k;
        if(bloomDay.size()<val) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(bloomDay,mid,m,k))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};