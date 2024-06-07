class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>st(dictionary.begin(),dictionary.end());
        bool isfound=false;
        string ans="";
        string temp="";
        for(auto &it:sentence){
            if(it!=' '){
                temp+=it;
                if(!isfound && st.find(temp)!=st.end()){
                    ans+=temp;
                    isfound=true;
                }
            }
            else{
                if(!isfound) ans+=temp;
                ans+=" ";
                temp="";
                isfound=false;
            }
        }
        if(!isfound) ans+=temp;
        return ans;
    }
};