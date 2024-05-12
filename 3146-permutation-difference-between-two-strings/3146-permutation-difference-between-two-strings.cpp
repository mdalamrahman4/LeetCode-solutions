class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>arr1(26,0),arr2(26,0);
        for(int i=0;i<s.size();i++){
            arr1[s[i]-'a']=i;
            arr2[t[i]-'a']=i;
        }
        int sum=0;
        for(int i=0;i<26;i++){
            sum+=abs(arr1[i]-arr2[i]);
        }
        return sum;
    }
};