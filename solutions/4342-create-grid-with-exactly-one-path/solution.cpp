class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> v;
        for(int i=0;i<m;i++){
            string s;
            for(int j=0;j<n;j++){
                if(i==m-1){
                    s += '.';
                }else if(j==0){
                   s+='.'; 
                }
                else s+='#';
            }
            v.push_back(s);
        }
        return v;
    }
};
