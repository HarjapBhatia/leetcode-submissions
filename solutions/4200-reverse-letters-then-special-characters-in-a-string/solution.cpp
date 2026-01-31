class Solution {
public:
    string reverseByType(string s) {
        string a = s;
        int l=0, r=s.size()-1;
        while(l<r){
            if(!isalpha(a[l]) && !isalpha(a[r])) swap(a[l], a[r]), l++, r--;
            else if(isalpha(a[l])) l++;
            else if(isalpha(a[r])) r--;
        }
        
        l=0, r=s.size()-1;
        while(l<r){
            if(isalpha(a[l]) && isalpha(a[r])) swap(a[l], a[r]), l++, r--;
            else if(!isalpha(a[l])) l++;
            else if(!isalpha(a[r])) r--;
        }
        return a;
    }
};
