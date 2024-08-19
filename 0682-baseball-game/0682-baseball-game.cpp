class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(auto it:operations){
            if(it=="+"){
                int temp=st.top();
                st.pop();
                int temp2=st.top();
                st.push(temp);
                st.push(temp+temp2);
            }
            else if(it=="D"){
                st.push(2*st.top());
            }
            else if(it=="C"){
                st.pop();
            }
            else{
                st.push(stoi(it));
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};