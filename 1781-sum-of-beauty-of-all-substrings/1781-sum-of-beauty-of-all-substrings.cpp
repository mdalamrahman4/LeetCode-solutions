class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int beauty=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            int minf=INT_MAX;
            int maxf=INT_MIN;
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                maxf=max(maxf,freq[s[j]-'a']);
                minf=freq[s[j]-'a'];
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        minf=min(minf,freq[k]);
                    }
                }
                beauty+=(maxf-minf);
            }  
        }
        return beauty;
    }
};