class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n=nums.size();
        long long ans=0;
        int i=0;
        while(i<n){
            if(s[i]=='1'){
                int st=i;
                while(i<n&&s[i]=='1')i++;
                int ed=i-1;
                if(st==0){
                    for(int it=st;it<=ed;it++) ans+=nums[it];
                }
                else{
    
                    long long cur=0;
                    int mi=nums[st-1];
                    for(int j=st-1;j<=ed;j++){
                        cur += nums[j];
                        if(nums[j] < mi){
                            mi=nums[j];
                        }
                    }
                    ans+=(cur-mi);
                    
                }
            }else i++;
        }
        return ans;
    }
};
