class Solution {
public:
    string sortVowels(string s) {
        string vowels = "";
        for(char ch : s) {
            if(isVowel(ch)) vowels.push_back(ch);
        }
        sort(vowels.begin(), vowels.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) s[i] = vowels[j++];
        }
        return s;
    }

private:
    bool isVowel(char ch) {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
               ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
    }
};
