class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int x=nums[0],i=0, n=nums.size();
        for(i=1;i<n;i++){
            if(nums[i]-nums[i-1]!=1){
                break;
            } 
            x += nums[i];
        }
        unordered_set<int> us(nums.begin(),nums.end());
        while(us.count(x)){
            x++;
        }
        return x;
    }
};
