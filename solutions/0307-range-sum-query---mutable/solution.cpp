class SegTree{
public:
    vector<int> sgt, vec;
    SegTree(int n, vector<int> v){
        sgt.resize(4*n);
        vec = v;
        build(0, n-1, 1);
    }
    void build(int s, int e, int idx){
        if(s==e){
            sgt[idx]=vec[s]; return;
        }
        int mid = (s+e)>>1;
        build(s, mid, 2*idx);
        build(mid+1, e, 2*idx+1);
        sgt[idx] = sgt[2*idx]+sgt[2*idx+1];
    }
    void update(int s, int e, int idx, int pos, int val){
        if(s==e){
            sgt[idx] = val; return;
        }
        int mid = (s+e)>>1;
        if(mid >= pos) update(s, mid, 2*idx, pos, val);
        else update(mid+1, e, 2*idx+1, pos, val);
        sgt[idx] = sgt[2*idx]+sgt[2*idx+1];
    }
    int rngsum(int s, int e, int idx, int l, int r){
        if(s>r || e<l) return 0;
        if(s >= l && e <= r) return sgt[idx];
        int mid = (s+e)>>1;
        int lef = rngsum(s, mid, 2*idx, l, r);
        int rig = rngsum(mid+1, e, 2*idx+1, l, r);
        return lef+rig;
    }
};

class NumArray {
public:
    int n;
    SegTree st;
    NumArray(vector<int>& nums) : n(nums.size()), st(n, nums){}
    
    void update(int index, int val) {
        st.update(0, n-1, 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return st.rngsum(0, n-1, 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
