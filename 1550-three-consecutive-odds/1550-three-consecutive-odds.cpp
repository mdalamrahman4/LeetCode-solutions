class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;
        vector<int>oddy;
        for(int i=0;i<n;i++){
            if(arr[i]%2==1){
                oddy.push_back(arr[i]);
            }
            else{
                oddy.clear();
            }
            if(oddy.size()>=3)  return true;
        }
        return false;
    }
};