class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f=-1,s=-1;
        for(int x : nums){
            if(x>f){s=f;f=x;}
            else if(x>s){s=x;}
        }
        return (f-1)*(s-1);
    }
};
