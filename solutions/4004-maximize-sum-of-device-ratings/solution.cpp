#define ll long long
class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m=units.size(), n=units[0].size();
        if(n==1 && m==1) return 1ll*units[0][0];
        if(m==1){
            int ans = *min_element(units[0].begin(), units[0].end());
            return 1ll*ans;
        }
        if(n==1){
            ll ans =0;
            for(auto x : units) ans += x[0];
            return ans;
        }
        vector<vector<int>> vec;

        for(auto &a : units){
            int mi=1e9, smi=1e9;
            for(int i : a){
                if(i < mi){
                    smi = mi;
                    mi = i;
                }else if(i < smi){
                    smi = i;
                }
            }
            vec.push_back({mi, smi});
        }

        sort(vec.begin(), vec.end(), [&](vector<int>&a, vector<int>&b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        // for(auto x : vec){
        //     for(int i : x) cout << i << " ";
        //     cout << "\n";
        // }

        ll ans = 0;
        int mi = vec[0][0];
        for(int i=1;i<m;i++){
            ans += vec[i][1];
            mi = min(mi, vec[i][0]);
        }

        return ans+mi;

    }
};
