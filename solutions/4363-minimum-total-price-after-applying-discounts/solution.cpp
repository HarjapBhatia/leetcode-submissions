class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        sort(p.rbegin(),p.rend());
        sort(d.rbegin(),d.rend());
        int n=p.size();
        double ans=0;
        for(int i=0;i<n;i++){
            if(i >= d.size()) ans += p[i];
            else {
                ans += (1.00000*(p[i] * (100-d[i]))/100);
            } 
        }
        return (ans*100000.0)/100000.0;
    }
};
