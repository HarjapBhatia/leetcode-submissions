class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> vec;
        if(num%3!=0) return vec;
        num/=3;
        num--;
        vec.push_back(num);
        vec.push_back(num+1);
        vec.push_back(num+2);
        return vec;
    }
};
