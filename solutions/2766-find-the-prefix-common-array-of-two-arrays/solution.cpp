class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> fq(n+1,0);
        int cnt=0, i=0;
        vector<int> ans;
        while(i<n){
            fq[A[i]]++; fq[B[i]]++;
            if(fq[A[i]] == 2 && fq[B[i]] == 2){
                if(A[i] == B[i]) cnt ++;
                else cnt += 2;
            }else if(fq[A[i]] == 2 || fq[B[i]] == 2) cnt++;
            ans.push_back(cnt); i++;
        }
        return ans;
    }
};
