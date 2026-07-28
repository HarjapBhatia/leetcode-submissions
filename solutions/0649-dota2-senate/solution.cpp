class Solution {
public:
    string predictPartyVictory(string s) {
        queue<char> q;
        int cr=0,cd=0; // count rad. and dire 
        for(char x : s){
            q.push(x);
            x=='R' ? cr++ : cd++;
        }
        int br=0,bd=0;  // count ban_r and ban_d
        while(cr>0 && cd>0){    
            char x = q.front(); q.pop();
            if(x == 'R'){
                if(br > 0) br--, cr--;
                else{
                    bd++; q.push(x);
                }
            }else{
                if(bd > 0) bd--, cd--;
                else{
                    br++; q.push(x);
                }
            }
        }
        if(q.front() == 'R') return "Radiant";
        return "Dire";
    }
};
