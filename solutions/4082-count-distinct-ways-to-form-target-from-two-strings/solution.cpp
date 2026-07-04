#define kuchbhi 1000000007
#define ll long long
class Solution {
public:
    // it, s1_i, s2_i, is1, is2
    int dp[101][101][101][2][2];
    int f(int i, int j, int k, string &s1, string &s2, string &tg, bool is1, bool is2){
        if(i>=tg.size()){
            if(is1&&is2) return 1;
            return 0;
        }
        if(dp[i][j][k][is1][is2] != -1) return dp[i][j][k][is1][is2];

        ll ways=0;
        for(int x=j;x<s1.size();x++){
            if(s1[x] == tg[i]){
                ways = (ways + f(i+1,x+1,k,s1,s2,tg,1,is2)) % kuchbhi;
            }
        }
        for(int x=k;x<s2.size();x++){
            if(s2[x] == tg[i]){
                ways = (ways + f(i+1,j,x+1,s1,s2,tg,is1,1)) % kuchbhi;
            }
        }

        return dp[i][j][k][is1][is2] = ways%kuchbhi;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp, -1, sizeof(dp));
        //is1 & is2 = is char from respective word included or not
        return f(0,0,0,word1,word2,target,false,false);
    }
};
