class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int odds=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2==1){
                odds++;
            }
            else{
                odds=0;
            }
            if(odds>=3)  return true;
        }
        return false;
    }
};