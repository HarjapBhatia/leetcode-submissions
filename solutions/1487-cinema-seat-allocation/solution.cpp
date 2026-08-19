class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_map<int, vector<int>> v;
        for(auto a : res){
            v[a[0]].push_back(a[1]);
        }

        int ans=2*n;
        for(auto it : v){
            int fam=0,f1=1,f2=1,f3=1;
                
            for(int i : it.second){
                if(2<=i && i<=5) f1=0;
                if(4<=i && i<=7) f2=0;
                if(6<=i && i<=9) f3=0;
            }
            if(f1&&f3) fam=2;
            else if(f1||f2||f3) fam=1;
            else fam=0;
            ans += fam-2;
        }
        return ans;
    }
};
