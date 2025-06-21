class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uset(nums.begin(), nums.end());
        int maxlen = 0;
        for (int num : uset){
            int currElement = num;
            if(uset.find(num-1)==uset.end()){
                int currLength = 1;
                while(uset.find(currElement+1)!=uset.end()){
                    currLength++;
                    currElement++;      
                }
                maxlen = max(maxlen,currLength);
            }
        }
        return maxlen;
    }
};
