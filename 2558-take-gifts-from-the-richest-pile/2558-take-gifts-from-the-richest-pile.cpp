class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq(gifts.begin(),gifts.end());
        while(k--){
            int temp=pq.top();
            if(temp==1) break;
            pq.pop();
            pq.push(floor(sqrt(1.0*temp)));
        }
        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};