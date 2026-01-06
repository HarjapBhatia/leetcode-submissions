class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sm = 0, sg=0;
        for(int x : nums){
            x < 10 ? sg += x : sm += x;
        }
        return sg != sm;
    }
};
