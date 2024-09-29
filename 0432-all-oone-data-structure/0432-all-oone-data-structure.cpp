class AllOne {
public:
    unordered_map<string,int> mp;
    multiset<pair<int, string>> ordered;

    AllOne() {}
    
    void inc(string key) {
        if (mp.count(key)) {
            ordered.erase(ordered.find({mp[key], key}));
        }
        mp[key]++;
        ordered.insert({mp[key], key});
    }
    
    void dec(string key) {
        if (mp.count(key)) {
            ordered.erase(ordered.find({mp[key], key}));
            mp[key]--;
            if (mp[key] == 0) {
                mp.erase(key);
            } else {
                ordered.insert({mp[key], key});
            }
        }
    }
    
    string getMaxKey() {
        if (ordered.empty()) return "";
        return ordered.rbegin()->second;
    }
    
    string getMinKey() {
        if (ordered.empty()) return "";
        return ordered.begin()->second;
    }
};
