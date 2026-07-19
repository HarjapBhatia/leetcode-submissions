class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> fq(26,false);
        string ans;
        unordered_map<char,int> mp;
        for(char x : s) mp[x]++;

        for(char x : s){
            while(!fq[x-'a'] && !ans.empty() &&
             mp[ans.back()]>0 && x < ans.back()){
                fq[ans.back()-'a']=false; ans.pop_back(); 
            }

            mp[x]--;
            if(!fq[x-'a']){
                fq[x-'a']=true; ans.push_back(x); 
            }
        }

        return ans;
    }
};
