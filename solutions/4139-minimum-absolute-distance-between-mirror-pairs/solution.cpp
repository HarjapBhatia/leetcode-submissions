class Solution {
public:
    int r(int n){
        int x = 0;
        while(n>0){
            x = (10*x) + (n%10);
            n /= 10;
        }
        return x;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        map<int, int> mp;
        int mi = 1e5;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(mp.find(x) != mp.end())
                mi = min(mi, i-mp[x]);
            mp[r(x)] = i;
        } 
        return mi==1e5 ? -1 : mi ;
    }
};
