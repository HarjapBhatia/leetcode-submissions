class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<int> wt;
        for(string s : words){
            int totwt=0;
            for(char c : s)
                totwt += weights[c-'a'];
            wt.push_back(totwt);
        }
        string res;
        for(int i : wt){
            i%=26;
            res += (char)(25-i+'a');
        }
        return res;
    }
};
