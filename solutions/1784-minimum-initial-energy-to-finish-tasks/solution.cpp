class Solution {
public:
    int minimumEffort(vector<vector<int>>& tk) {
        sort(tk.begin(), tk.end(), [](vector<int>&a, vector<int>&b){
            return (a[1]-a[0]) > (b[1]-b[0]);
        });
        // method-1: 
        // int ans=0, cur=0;
        // for(auto i : tk){
        //     if(i[1] > cur){
        //         ans += (i[1]-cur);
        //         cur += (i[1]-cur);
        //     }
        //     cur -= i[0];
        // }
        // return ans;

        //method-2:
        int ans = tk[0][1];
        int cur = ans;
        for(auto i : tk){
            if(cur >= i[1]){
                cur -= i[0];
            }else {
                ans += (i[1]-cur);
                cur = i[1];
                cur -= i[0];
            }
        }
        return ans;

    }
};
