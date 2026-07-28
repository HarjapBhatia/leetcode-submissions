class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int>cnt(26,0);    
        for(char x : s) cnt[x-'a']++;
        // string res;
        vector<char> res(n);
        int i=0,j=n-1;
        for(int k=0;k<26;k++){
            while(cnt[k]>1){
                res[i++] = k+'a';
                res[j--] = k+'a';
                cnt[k] -= 2;
            }
        }
        for(int k=0;k<26;k++){
            if(cnt[k]){
                res[i++] = k+'a';
            }
        }
        string ans;
        for(char cc : res) ans += cc;
        return ans;
    }
};
