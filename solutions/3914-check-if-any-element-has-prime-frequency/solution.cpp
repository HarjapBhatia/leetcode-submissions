class Solution {
public:
    bool check(int n){
        if(n == 1) return false;
        if(n == 2) return true;
        if(n%2 == 0) return false;
        for(int i = 3;i<=sqrt(n); i+=2){
            if(n%i == 0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i : nums) freq[i]++;
        for(auto it : freq){
            if(check(it.second)) return true;
        }
        return false;
    }
};
