class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cl=0, cr=0, cu=0;
        for(char x : moves){
            if(x == 'L') cl++;
            else if(x=='R') cr++;
            else cu++;
        }
        return abs(cl-cr)+cu;
    }
};
