class Solution {
public:
    vector<long long> maximumEvenSplit(long long fs) {
        vector<long long> res;
        if(fs&1) return res;
        long long st=2, end=fs;
        while(st<=end){
            res.push_back(st);
            end -= st;
            st += 2;
        }
        if(end==0) return res;
        long long n = res.size();
        res[n-1] += end;
        return res;

        // method - 2:
        // vector<long long> res;
        // if(fs&1) return res;
        // set<long long> vis;
        // long long i=2;
        // while(fs > 0 && i < fs){
        //     if(abs(fs-i) == i) break;
        //     if(!vis.count(abs(fs-i)) && !vis.count(i)){
        //         vis.insert(i); fs-=i;
        //     }
        //     i+=2;
        // }
        // vis.insert(fs);
        // for(long long x: vis) res.push_back(x);
        // return res;
    }
};
