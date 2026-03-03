class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n=nums.size();
        vector<int> fq(101, 0);
        for(int i : nums) fq[i]++;
        int x = -1;
        for(int i=0;i<101;i++){
            if(fq[i]!=0) {x = i; break;}
        }
        int y = -1;
        for(int i=x+1;i<101;i++){
            if(fq[i]!=0 && fq[i]!=fq[x]) {y = i; break;} 
        }
        if(x == -1 || y==-1) return {-1,-1};
        return {x,y};
    }
};
