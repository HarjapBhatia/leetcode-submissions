class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int i=0,cnt=1;
        while(i<n){
            int j=i;
            while(j<n && word[j]==word[i]) j++;
            int len = j-i;
            if(len>1) cnt += len-1;
            i=j;
        }
        return cnt;
    }
};
