#include <map>
#include <climits>
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>freq;
        int maxInt = INT_MIN;
        for(int x : arr){
            freq[x]++;
        }
        for(auto it : freq){
            if (it.first == it.second){
                maxInt = max(maxInt, it.first);
            }
        }
        if(maxInt == INT_MIN) return -1;
        else return maxInt;
    }
};
