class MinStack {
    stack<long long int> st;    
    stack<long int> mi;    
public:
    MinStack() {}
    
    void push(long long int val) {
        st.push(val);
        if(mi.empty() || mi.top() > val) mi.push(val);
        else mi.push(mi.top());
    }
    
    void pop() {
        st.pop();
        mi.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mi.top();
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
