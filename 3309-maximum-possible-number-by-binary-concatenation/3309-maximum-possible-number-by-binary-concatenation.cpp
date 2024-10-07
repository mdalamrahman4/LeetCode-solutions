class Solution {
public:
    string convert(int no){
        if(no==0)   return "0";
        string temp="";
        while(no){
            temp+=(to_string(no%2));
            no/=2;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<string>st;
        for(auto it:nums){
            st.push_back(convert(it));
        }
        vector<int>ans;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(i!=j && i!=k && j!=k)    ans.push_back(stoi(st[i]+st[j]+st[k],nullptr,2));
                }
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};