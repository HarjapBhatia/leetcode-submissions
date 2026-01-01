class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1] += 1;
        for(int i=n-1;i>0;i--){
            if(digits[i] < 9) return digits;
            digits[i-1] += digits[i]/10;
            digits[i] %= 10;
        }
        if(digits[0] > 9) {
            digits.insert(digits.begin(), digits[0]/10);
            digits[1] %= 10;
        }
        return digits;
    }
};
