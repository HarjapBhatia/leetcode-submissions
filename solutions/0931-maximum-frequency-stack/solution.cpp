class FreqStack {
    unordered_map<int,int> umap;
    unordered_map<int,stack<int>> res;
    int mf = 0;
public:
    FreqStack() {
        mf = 0;
    }
    
    void push(int val) {
        int f = ++umap[val];
        mf = max(mf,f);
        res[f].push(val);
    }
    
    int pop() {
        int val = res[mf].top();
        res[mf].pop();
        umap[val]--;
        if(res[mf].empty()) mf--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
