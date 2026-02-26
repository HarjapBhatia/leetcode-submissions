class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val =0, cnt =0;
        for(int i : nums){
            if(cnt == 0) val = i;
            if(i == val) cnt++;
            else cnt--;
        }
        return val;
    }
};
