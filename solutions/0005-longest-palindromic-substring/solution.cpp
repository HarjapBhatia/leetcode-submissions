class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        for(int i=0;i<n;i++){
            int st=i, e=i; //odd
            while(st>=0 && e<n && s[st]==s[e]){
                st--; e++;
            }
            string temp = s.substr(st+1, e-st-1);
            if(temp.size() > res.size()) res = temp;
            
            st=i, e=i+1; //even
            while(st>=0 && e<n && s[st]==s[e]){
                st--; e++;
            }
            temp = s.substr(st+1, e-st-1);
            if(temp.size() > res.size()) res = temp;

        }
        return res;
    }
};
