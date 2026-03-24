class Solution {
public:
    int compress(vector<char>& chars) {
        // method-1:
        // string s;
        // int j = 0, cnt = 1;
        // for(int i=1;i<chars.size();i++){
        //     if(chars[j] == chars[i]) cnt++;
        //     else{
        //         s += chars[j];
        //         if(cnt != 1) s += to_string(cnt);
        //         j = i;
        //         cnt = 1;
        //     }
        // }
        // s += chars[j];
        // if(cnt != 1) s += to_string(cnt);
        // for(int i=0;i<s.size();i++) chars[i] = s[i];
        // return s.size();


        // method-2:
        int n = chars.size();
        int i=0; int j =0 ;
        while(i<n){
            char c = chars[i++];
            int cnt = 1;
            while(i<n && chars[i] == c){
                cnt++; i++;
            }
            chars[j++] = c;
            if(cnt!=1){
                string s = to_string(cnt);
                for(char x : s) chars[j++] = x;
            }
        } 
        return j;
    }
};
