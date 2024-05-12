class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>arr(26,0);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']=i;
        }
        int sum=0;
        for(int i=0;i<t.size();i++){
            sum+=abs(arr[t[i]-'a']-i);
        }
        return sum;
    }
};