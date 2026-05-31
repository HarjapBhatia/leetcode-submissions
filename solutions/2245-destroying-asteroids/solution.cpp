class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        long long t = mass;
        int j=0;
        while(j<n){
            if(t >= a[j]){
                t += a[j]; j++;
            }else break;
        }
        return j == n;
    }
};
