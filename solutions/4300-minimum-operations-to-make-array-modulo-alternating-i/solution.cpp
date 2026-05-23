class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        for(int &i : nums) i%=k;
        int cnt = INT_MAX;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x==y) continue;
                int temp=0;
                for(int i=0;i<n;i++){
                    if(i&1){
                        int d = abs(nums[i]-y);
                        temp += min(d, k-d);
                    }else{
                        int d = abs(nums[i]-x);
                        temp += min(d, k-d);
                    }
                }
                cnt = min(cnt, temp);
            }
        }
        return cnt;
    }
};
