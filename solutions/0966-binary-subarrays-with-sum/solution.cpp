/*
method-1: the generic approach
use map to count the prefix sums and their freq. and on every cur, look if there exist cur-goal earlier you've calculated?
if yes, then cnt += map[cur-goal]
cuz, cur - (cur-goal) = goal

method-2:
finding number of subarrays with cur1 <= goal and cur1 <= goal-1
and then subtract both cur1-cur2, just like pref sum
*/
class Solution {
public:
    int f(vector<int>&nums, int goal){
        if(goal < 0) return 0;
        int cur=0,cnt=0,n=nums.size(),i=0;

        for(int j=0;j<n;j++){
            cur += nums[j];
            while(cur > goal){
                cur -= nums[i++];
            }
            cnt += j-i+1;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // app-1
        // unordered_map<int,int> mp;
        // int cnt=0,cur=0;
        // mp[0]=1;
        // for(int x : nums){
        //     cur += x;
        //     if(mp.count(cur-goal)){
        //         cnt += mp[cur-goal];
        //     }
        //     mp[cur]++;
        // }
        // return cnt;

        // app-2
        return f(nums,goal)-f(nums,goal-1);
    }
};
