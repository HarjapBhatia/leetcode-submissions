class SummaryRanges {
public:
    vector<int> par;
    set<int> s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(s.empty()) return {};
        vector<vector<int>> res;
        int lef=-1, rig=-1;
        for(int i : s){
            if(lef<0) lef = rig = i;
            else if(i == rig+1) rig=i;
            else{
                res.push_back({lef,rig});
                lef=rig=i;
            }
        }
        res.push_back({lef,rig});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
