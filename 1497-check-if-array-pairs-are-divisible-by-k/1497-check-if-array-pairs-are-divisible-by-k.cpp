class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>mp(k,0);
        for(auto &it:arr){
            mp[(it%k+k)%k]++;
        }
        if(mp[0]%2!=0)  return false;
        for(int rem=1;rem<k;rem++){
            if(mp[k-rem]!=mp[rem])  return false;
        }
        return true;
    }
};