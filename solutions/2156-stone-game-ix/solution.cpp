class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0=0,c1=0,c2=0;
        for(int i:stones){
            int x=i%3;
            if(!x) c0++;
            else{
                x==1 ? c1++:c2++;
            }
        }
        if(c0%2==0) return c1>0 && c2>0;
        return abs(c1-c2)>2;
    }
};
