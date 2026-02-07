class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, cnt =0;
        for(char x : s){
            if((x-'0')%2 == 0) cnt++;
            else if(cnt) ans++, cnt--;
        }
        return ans;
    }
};
