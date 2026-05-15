class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, vector<int>>> pq;
        for(auto a : points){
            int d = (a[0]*a[0]) + (a[1]*a[1]);
            pq.push({d, a});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
