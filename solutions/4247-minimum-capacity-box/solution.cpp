class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int mi = 101, mi_ix = -1;
        for(int i=0;i<capacity.size();i++){
            if(itemSize <= capacity[i] && capacity[i] < mi) mi = capacity[i], mi_ix = i;
        }
        return mi_ix;
    }
};
