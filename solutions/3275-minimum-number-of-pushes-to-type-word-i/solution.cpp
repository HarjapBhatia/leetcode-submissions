class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8) return n;
        int rep = n/8, rem=n%8;
        // int ans = 8*rep;
        int ans=0, i=1;
        for(i=1;i<=rep;i++){
            ans += 8*i;
        }
        ans += rem*i;

        return ans;
    }
};
