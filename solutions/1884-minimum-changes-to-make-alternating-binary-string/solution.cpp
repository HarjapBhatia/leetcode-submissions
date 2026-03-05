class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n==1) return 0;
        int c1 =0, c2=0;
        for(int i=0;i<n;i++){
            // 1010...
            if(i%2==0 && s[i]=='1') c1++;
            else if((i%2==1 && s[i]=='0'))c1++;
            
            // 0101...
            if(i%2==0 && s[i]=='0') c2++;
            else if((i%2==1 && s[i]=='1'))c2++;
        }

        return min(c1,c2);
    }
};
