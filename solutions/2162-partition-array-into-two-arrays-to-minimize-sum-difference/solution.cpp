/*
idea : 
    - dividing the array (2n) into two parts (left & right) (n each) looking at both segment and generating the permutations (subsets in 2^n) 
    - total = leftsum + rightsum, both segment needs sum closer to total/2 so for rightsum, we need rightsum = total - 2*leftsum and viceversa
    - sorting the right vector and on each sum vector in left, we'll look for n-k in right usign binary search(lower bound).
    - if we get an iterator, look on its left. get the min ans.
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<vector<int>> left(n+1), right(n+1);
        int total = accumulate(nums.begin(), nums.end(),0);

        for(int msk=0;msk < (1<<n); msk++){
            int cnt=0, lsm=0, rsm=0;
            for(int i=0;i<n;i++){
                if(msk & (1<<i)){
                    cnt++; 
                    lsm += nums[i];
                    rsm += nums[i+n];
                }
            }
            left[cnt].push_back(lsm);
            right[cnt].push_back(rsm);
        }

        for(int i=0;i<n;i++){
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;
        for(int k=0;k<=n;k++){
            for(int lsm : left[k]){
                int need = total/2 - lsm;
                auto &vec = right[n-k];
                auto it = lower_bound(vec.begin(),vec.end(),need);
                if(it!=vec.end()){
                    int chosen = *it + lsm;
                    ans = min(ans, abs(total - 2*chosen));
                }
                if(it!=vec.begin()){
                    --it;
                    int chosen = *it + lsm;
                    ans = min(ans, abs(total - 2*chosen));
                }
            }
        }
        return ans;
    }
};
