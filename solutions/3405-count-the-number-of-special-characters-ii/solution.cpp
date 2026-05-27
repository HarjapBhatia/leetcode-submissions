class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0, n=word.size();
        vector<int> uc(26,n+1), lc(26,-1);
        for(int i=0;i<n;i++){
            char w = word[i];
            if(w>='a' && w<='z') 
                lc[w-'a'] = max(lc[w-'a'], i);
            else 
                uc[w-'A'] = min(uc[w-'A'], i);
        }
        // for(int i : lc) cout << i << " ";
        // cout << "\n";
        // for(int i : uc) cout << i << " ";
        for(int i=0;i<26;i++){
            if(lc[i]!=-1 && uc[i]!=n+1 && lc[i] < uc[i]) ans++;
        }

        return ans;
    }
};
