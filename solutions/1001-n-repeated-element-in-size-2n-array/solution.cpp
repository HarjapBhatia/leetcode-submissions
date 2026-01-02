class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int cnt = n/2;
        unordered_map<int,int> freq;
        for(int x: nums) freq[x]++;
        for(auto it: freq){
            if(it.second == cnt) return it.first;
        }
        return -1;
    }
};
