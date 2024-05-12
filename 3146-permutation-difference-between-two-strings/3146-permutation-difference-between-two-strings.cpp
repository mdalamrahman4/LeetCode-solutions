class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<pair<int,int>>arr(26);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a'].first=i;
            arr[t[i]-'a'].second=i;
        }
        int sum=0;
        for(int i=0;i<26;i++){
            sum+=abs(arr[i].first-arr[i].second);
        }
        return sum;
    }
};