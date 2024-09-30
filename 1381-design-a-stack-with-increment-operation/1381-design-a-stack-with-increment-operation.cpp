class CustomStack {
public:
    int mxsize;
    vector<int>st;
    CustomStack(int maxSize) {
        mxsize=maxSize;
    }
    
    void push(int x) {
        if(st.size()<mxsize){
            st.push_back(x);
        }
    }
    
    int pop() {
        if(st.size()>0){
            int val=st.back();
            st.pop_back();
            return val;
        }
        else{
            return -1;
        }
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<st.size();i++){
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */