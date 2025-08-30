class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int, int> map;
        if (n == 0) {
            map[0]++;
        }
        while(n!=0){
            int re = n%10;
            map[re]++;
            n/=10;    
        }
        int leastDigit = -1;
        int leastCount = INT_MAX;
    
        for (auto &p : map) {
            if (p.second < leastCount) {
                leastCount = p.second;
                leastDigit = p.first;
            }
        }
        
        return leastDigit;
    }
};
