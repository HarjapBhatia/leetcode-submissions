class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n=w1.size(), m=w2.size();
        vector<int> last_idx(m,-1);
        int i=n-1, j=m-1;
        while(i>=0){
            if(j>=0 && w1[i] == w2[j]){
                last_idx[j] = i;
                j--;
            }            
            i--;
        }
        
        vector<int> ans; j=0;
        bool f=false;
        for(i=0;i<n;i++){
            if(j==m) break;
            if(w1[i]==w2[j]) {
                j++; ans.push_back(i);
            }
            else if(!f && (j==m-1 || last_idx[j+1] > i)){
                f=!f; j++; ans.push_back(i);
            }
        }

        if(j==m) return ans;
        return {};
    }
};
