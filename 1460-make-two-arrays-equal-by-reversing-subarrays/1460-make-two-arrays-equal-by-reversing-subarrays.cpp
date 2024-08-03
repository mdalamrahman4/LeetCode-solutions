class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        vector<int>freq(1001,0);
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
            freq[target[i]]--;
        }
        for(int i=0;i<1001;i++){
            if(freq[i]!=0)  return false;
        }
        return true;
    }
};