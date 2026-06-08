class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pv) {
        // int n = nums.size();
        // vector<int> sm, lg;
        // int same=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i] < pv){
        //         sm.push_back(nums[i]);
        //     }else if(nums[i]>pv){
        //         lg.push_back(nums[i]);
        //     }else same++;
        // }
        // vector<int> ans;
        // for(int i=0;i<sm.size();i++){
        //     ans.push_back(sm[i]);
        // }
        // while(same--){
        //     ans.push_back(pv);
        // }
        // for(int i=0;i<lg.size();i++){
        //     ans.push_back(lg[i]);
        // }

        vector<int> ans;
        for(int x : nums){
            if(x < pv) ans.push_back(x);
        }
        for(int x : nums){
            if(x == pv) ans.push_back(x);
        }
        for(int x : nums){
            if(x > pv) ans.push_back(x);
        }
        return ans;
    }
};
