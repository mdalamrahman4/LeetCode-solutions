class MinStack {
public:
    stack<int>st1;
    stack<int>minstack;
    MinStack() {
        int val;
    }
    
    void push(int val) {
        st1.push(val);
        if(minstack.empty() || val<=minstack.top())  minstack.push(val);
    }
    
    void pop() {
        if(st1.top()==minstack.top())   minstack.pop();
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */