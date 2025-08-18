class CustomStack {
    vector<int> st;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this -> maxSize = maxSize;
    }
    
    void push(int x) {
        if((int)st.size() < maxSize){
            st.push_back(x);
        }
    }
    
    int pop() {
        if(!st.empty()) {
            int val = st.back();
            st.pop_back();
            return val;
        }else {return -1;}
    }
    
    void increment(int k, int val) {
        int lim = min(k, (int)st.size());
        for(int i=0; i<lim; i++){
            st[i] += val;
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
