class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n,false);
        dp[0] = true;
        // method - 1:
        // for(int i=1;i<n;i++){
        //     if(s[i] == '1') continue;
        //     for(int j=i-minJump; j>=max(0,i-maxJump);j--){
        //         if(dp[j]){
        //             dp[i]=true; break;
        //         }
        //     }
        //     // cout << dp[i] << " ";
        // }
        // return dp[n-1];

        //method-2:
        int cnt =0;
        for(int i=1;i<n;i++){
            if(i-minJump >= 0 && dp[i-minJump]) cnt++;
            if(i-maxJump > 0 && dp[i-maxJump-1]) cnt--;
            dp[i] = (cnt > 0 && s[i]=='0');
        }
        return dp[n-1];
    }
};
