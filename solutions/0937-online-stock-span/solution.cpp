class StockSpanner {
public:
    StockSpanner() {
        
    }
    vector<int> v;
    int next(int price) {
        int cnt=1;
        for(int j=v.size()-1;j>=0;j--){
            if(v[j] > price) break;
            cnt++;
        }
        v.push_back(price);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
