class Solution {
public:
    string compressedString(string word) {
        string s;
        int j=0, cnt = 1;
        for(int i=1;i<word.size();i++){
            if(word[j] == word[i] && cnt < 9)cnt++;
            else{
                s += (cnt+'0');
                s += word[j];
                j = i;
                cnt=1;
            }
        }
        s += (cnt+'0');
        s += word[j];
        
        return s;
    }
};
