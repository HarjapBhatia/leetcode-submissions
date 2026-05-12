class Solution {
public:
    int bagOfTokensScore(vector<int>& tk, int p) {
        int s=0,l=0,r=tk.size()-1, ans=0;
        sort(tk.begin(), tk.end());
        while(l<=r){
            if(p >= tk[l]){
                s++; p -= tk[l++];
                ans = max(ans, s);
            }else if(s>0){
                s--; p += tk[r--]; 
            }
            else break;
        }
        return ans;
    }
};
