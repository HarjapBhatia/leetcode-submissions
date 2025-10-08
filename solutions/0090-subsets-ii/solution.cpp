class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> uset;
        for(int i=0;i<(1<<n);i++){
            vector<int>vec;
            for(int j=0;j<n;j++){
                if((i>>j) & 1){
                    vec.push_back(nums[j]);
                }
            }
            sort(vec.begin(), vec.end());
            uset.insert(vec);
        }
        vector<vector<int>> res(uset.begin(),uset.end());
        return res;
    }
};
