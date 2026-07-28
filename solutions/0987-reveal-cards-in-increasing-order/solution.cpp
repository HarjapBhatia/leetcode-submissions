class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& d) {
        sort(d.begin(), d.end());
        int n=d.size();
        
        // app-1:
        vector<int> res(n);
        int i=0, j=0; bool skip=false;
        // here i is the index for res, and j is the jumps...
        // we'll only put element when we have an empty place in res AND the skip=true
        // skip is the toggle for alternative moves
        while(j<n){
            if(res[i] == 0){
                if(!skip){
                    res[i] = d[j++];
                }
                skip = !skip;
            }
            i = (i+1)%n;
        }
        return res;


        // app-2:
        // vector<int> res(n);
        // queue<int> q;
        // for(int i=0;i<n;i++) q.push(i);
        // for(int i=0;i<n;i++){
        //     res[q.front()] = d[i];
        //     q.pop();
        //     if(!q.empty()){
        //         int y=q.front(); q.pop();
        //         q.push(y);
        //     }
        // }
        // return res;
    }
};
