class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mi_odd = 1e9+1;
        bool has = false;
        for(int x : nums1){
            if(x%2){
                has=true;
                mi_odd = min(mi_odd, x);
            }
        }
        if(!has) return true;
        for(int x : nums1){
            if(x%2==0 && x<mi_odd) return false;
        }
        return true;
    }
};
