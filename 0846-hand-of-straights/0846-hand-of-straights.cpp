class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size()%k!=0)    return false;
        map<int,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        while(mp.size()){
            int first=mp.begin()->first;
            for(int i=0;i<k;i++){
                if(mp[first+i]==0)  return false;
                else{
                    mp[first+i]--;
                    if(mp[first+i]<1){
                        mp.erase(first+i);
                    }
                }
            }
        }
        return true;
    }
};