class Solution {
public:
    bool is(vector<int>&v, int mi, int o){
        long long cnt=0;
        for(int i:v){
            if(i > mi) cnt += ((i+mi-1)/mi)-1;
        }
        return cnt <= o;
    }

    int minimumSize(vector<int>& nums, int o) {
        int n=nums.size(), l=1, r=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=r){
            int mi = (l+r)>>1;
            if(is(nums,mi,o)){ // f,f,f,f,t,t,t..
                ans = mi; 
                r=mi-1; 
            }else{
                l=mi+1;
            }
        }
        return ans;
    }
};
