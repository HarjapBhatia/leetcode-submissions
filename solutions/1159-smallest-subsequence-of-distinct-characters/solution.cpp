class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> is(26,false);
        unordered_map<char,int> mp;
        string ans;
        for(char x : s) mp[x]++;

        for(char x : s){
            while(!ans.empty() && mp[ans.back()]>0 
                && !is[x-'a'] && ans.back() > x){
                is[ans.back()-'a']=false;
                ans.pop_back();
            }
            
            mp[x]--;
            if(!is[x-'a']){
                is[x-'a']=true;
                ans.push_back(x);
            }
        }
        return ans;
    }
};
