class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n = num1.size(), m = num2.size();
        vector<int> vec(m+n, 0);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                vec[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
                vec[i+j] += vec[i+j+1]/10;
                vec[i+j+1] %= 10;
            }
        }

        int i=0;
        string res = "";
        while(i<(m+n) && vec[i]==0) i++;
        while(i<(m+n)) res += (vec[i++]+'0');
        return res;
    }
};
