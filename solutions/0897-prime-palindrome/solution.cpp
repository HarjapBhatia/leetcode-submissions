class Solution {
public:
    bool ispal(int n){
        string s = to_string(n);
        int i=0, j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
    
    bool ispr(int x){
        if(x == 2) return true;
        if(x < 2 || x%2 == 0) return false;
        for(int i=3;i<=sqrt(x);i+=2){
            if(x%i==0) return false;
        }
        return true;
    }
    bool isevenlen(int x){
        return to_string(x).size()%2==0;
    }

    int primePalindrome(int n) {
        if(n==1) return 2;
        while(true){
            if(ispal(n) && ispr(n)) return n;
            if(n > 11 && isevenlen(n)) n = (int)pow(10, to_string(n).size());
            n++;
        }
    }
};
