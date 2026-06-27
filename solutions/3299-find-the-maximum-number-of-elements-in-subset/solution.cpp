class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> ump;
        for(int i : nums) ump[i]++;
        int cnt=0;
        if(ump.find(1) != ump.end()){
            cnt += (ump[1]&1 ? ump[1]:ump[1]-1);
        }
        ump.erase(1);
        for(auto& [v, _] : ump){
            int res = 0; long long x=v;
            while(ump.contains(x) && ump[x] > 1){
                res += 2; x*=x;
            } 
            cnt = max(cnt, res+(ump.contains(x) ? 1:-1));
        }
        return cnt;
    }
};
