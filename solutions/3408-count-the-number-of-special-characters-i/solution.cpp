class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lcnt[26] = {0};
        int ucnt[26] = {0};
        for(char c : word){
            if(c>='A' && c<='Z') ucnt[c-'A']++;
            else lcnt[c-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(lcnt[i]>0 && ucnt[i]>0) ans++;
        }
        return ans;
    }   
};
