class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int mx = 0;
        while(l<r){
            int ln = min(height[l], height[r]);
            int br = r-l;
            mx = max(mx, ln*br);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return mx;
    }
};
