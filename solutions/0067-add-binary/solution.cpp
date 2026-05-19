class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i=a.size()-1, j=b.size()-1;
        int cy = 0;
        while(i >= 0 && j >= 0){
            int ai = a[i]-'0', bi = b[j]-'0';
            if((ai^bi) == 0){ // 1 1 && 0 0
                if(cy != 0) res += '1';
                else res += '0';
                cy = ai&bi;
            }else{ // 1 0 && 0 1
                if(cy != 0) {res += '0'; cy = 1;}
                else {res += '1'; cy = 0;}
            }
            i--; j--;
        }

        while(j>=0){
            if(cy != 0) {
                int bit = b[j]-'0';
                res += ((cy^bit) + '0');
                cy = cy&bit;
            }
            else res += b[j];
            j--;
        }
        
        while(i>=0){
            if(cy != 0) {
                int bit = a[i]-'0';
                res += ((cy^bit) + '0');
                cy = cy&bit;
            }
            else res += a[i];
            i--;
        }

        if(cy != 0) res += (cy+'0');
        reverse(res.begin(), res.end());
        return res;
    }
};
