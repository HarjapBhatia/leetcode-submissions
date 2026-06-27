class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int ans=0;
        for(int i : us){
            int x = i;
            if(x == INT_MIN || us.find(x-1)==us.end()){
                int cur = 1;
                while(x != INT_MAX && us.find(x+1)!=us.end()) {cur++; x++;}
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
