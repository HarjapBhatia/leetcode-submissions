class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> us(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        us.erase(beginWord);

        while(!q.empty()){
            string w = q.front().first;
            int st = q.front().second;
            q.pop();
            
            if(w == endWord) return st;

            for(int i=0;i<w.size();i++){
                char chr = w[i];
                for(char c='a';c<='z';c++){
                    w[i]=c;
                    if(us.find(w) != us.end()){
                        us.erase(w);
                        q.push({w, st+1});
                    }
                }
                w[i]=chr;
            }

        }

        return 0;
    }
};
