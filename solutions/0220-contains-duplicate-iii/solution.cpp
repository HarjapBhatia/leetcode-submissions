class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int idx, int val) {
        int n=nums.size();
        multiset<long long> ms;
        int i=0,j=0;
        while(j<n)
        {
            if(ms.empty()){
                ms.insert(nums[j++]); continue;
            }
            if(j > idx){
                ms.erase(ms.find(nums[i++]));
            }            

            auto lb = ms.lower_bound((long long)nums[j]);
            int x = *lb;
            if((lb != ms.end() && abs(nums[j]-x) <= val) || 
                (lb != ms.begin() && abs(nums[j] - *(--lb))<=val))
                return true; 

            ms.insert(nums[j++]);
        }
        return false;
    }
};
