class Solution {
public:
    long long countSubstrings(string s, char c) {
        int cnt=0;
        for(char x : s){
            if(x == c) cnt++;
        }
        return (1ll*cnt*(cnt+1))/2;
    }
};
