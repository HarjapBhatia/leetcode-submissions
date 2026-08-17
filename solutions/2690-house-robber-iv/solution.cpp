class Solution {
public:
    bool is(int mi, vector<int>&v, int k){
        int cnt_k1=0, cnt_k2=0 , ans=INT_MAX;
        int n=v.size();
        for(int i=0;i<n;i++){
            if(v[i] > mi){ continue;}
            cnt_k1++; i++;
        }
        for(int i=1;i<n;i++){
            if(v[i] > mi){continue;}
            cnt_k2++; i++;
        }
        return cnt_k1 >= k || cnt_k2 >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        int ans=r;
        while(l<=r){
            int mi=(l+r)>>1;
            if(is(mi,nums,k)){
                ans = mi; r=mi-1;
            }else{
                l=mi+1;
            }
        }
        return ans;
    }
};
