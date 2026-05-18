class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int n = points.size(), cnt=1;
        int st = points[0][1];
        for(int i=1;i<n;i++){
            if(st >= points[i][0]) continue;
            else {
                cnt++; st = points[i][1];
            }
        }
        return cnt;
    }   
};
