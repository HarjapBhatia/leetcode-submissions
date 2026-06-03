class Solution {
public:
    int f(vector<int> &a1, vector<int> &a2, vector<int> &b1, vector<int> &b2){
        long long ans1 = LLONG_MAX;
        for(int i=0;i<a1.size();i++){
            ans1 = min(ans1, 1ll*(a1[i]+a2[i]));
        }
        long long ans2=LLONG_MAX;
        for(int i=0;i<b1.size();i++){
            ans2 = min(ans2, 1ll*(max(ans1, 1ll*b1[i])+b2[i]));
        }
        return ans2;
    }
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int x = f(lst,ld,wst,wd);
        int y = f(wst,wd,lst,ld);
        return min(x,y);
    }
};
