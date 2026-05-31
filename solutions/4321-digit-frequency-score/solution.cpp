class Solution {
public:
    int digitFrequencyScore(int n) {
        // vector<int> c(10,0);
        unordered_map<int,int> cnt;
        while(n>0){
            cnt[n%10]++;
            n/=10;
        }
        long long ans = 0;
        for(auto it : cnt){
            ans += it.first*it.second;
        }
        return (int) ans;
    }
};
