class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int ans = 0, i=0,j=0;
        while(i<n && j<m){
            if(i<=j && nums1[i]<=nums2[j]){
                ans = max(ans, j-i); j++;
            }else if(i<=j) i++;
            else j++;
        }
        return ans;
    }
};
