class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int n = p.size();
        sort(p.begin(), p.end());
        int cnt = 0;
        int i=0, j=n-1;
        while(i<=j){
            if(p[i]+p[j] <= limit) i++;
            j--; cnt++;
        }
        return cnt;
    }
};
