class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int n=cost.size();
        int ans =0, j=0;
        for(int i=0;i<n;i++){
            ans += cost[i];
            if(j==2){
                ans-=cost[i];
                j=0;
            }
            else j++;
        }
        return ans;
    }
};
