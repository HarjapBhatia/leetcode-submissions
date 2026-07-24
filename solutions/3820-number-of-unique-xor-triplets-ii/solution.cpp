class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int msb=1;
        int mx=*max_element(nums.begin(),nums.end());
        while(mx>=msb) msb<<=1;
        
        vector<int> o(msb,0),s(msb,0),t(msb,0);
        for(int i : nums){
            o[i]=1;
            for(int j=0;j<msb;j++){
                if(o[j]) s[i^j]=1;
            }
        }
        for(int i : nums){
            for(int j=0;j<msb;j++){
                if(s[j]) t[i^j]=1;
            }
        }
        int cnt=0;
        for(int i=0;i<msb;i++){
            if(t[i]) cnt++;
        }
        return cnt;
    }
};
