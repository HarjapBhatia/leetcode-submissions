class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size(), ans = 1e5;
        for(int i=0;i<n;i++){
            if(words[i] == target){
                int x = abs(i-startIndex);
                int mi = min(x, abs(n-x));
                ans = min(ans, mi);
            }
        }
        return ans<n ? ans : -1;
    }
};
