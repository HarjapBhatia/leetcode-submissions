class Solution {
public:
    bool bs(vector<int> vec,int tg, int s, int e){
        while(s<=e){
            int m = (s+e)/2;
            if(vec[m] == tg) return true;
            else if(vec[m] > tg) e = m-1;
            else s = m+1;
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size(), ix = n-1;
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]) {ix = i; break;} 
        }    
        if(target >= nums[0] && target <= nums[ix]) return bs(nums, target, 0, ix);
        else return bs(nums, target, ix+1, n-1);
    }
};
