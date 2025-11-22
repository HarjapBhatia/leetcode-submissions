class Solution {
public:
    int count(int n){
        string s = to_string(n);
        int sz = s.size();
        int cnt = 0;
        for(int i=1;i<sz-1;i++){
            if((s[i] > s[i+1] && s[i] > s[i-1]) || (s[i] < s[i+1] && s[i] < s[i-1])) cnt++;    
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for(int i=num1;i<=num2;i++){
            res += count(i);
        }
        return res;
    }
};
