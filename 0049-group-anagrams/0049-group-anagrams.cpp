class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        for(auto&i: strs)
            {
            string t=i;//created a copy
			
            sort(t.begin(),t.end());//sorted to get the key
            mp[t].push_back(i);//pushed the initial string in map
        }
        for(auto&i:mp)
            {
            res.push_back(i.second);
            }
        return res;
    }
};