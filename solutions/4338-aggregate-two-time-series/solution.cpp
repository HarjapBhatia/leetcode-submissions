typedef long long ll;
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        int m=s1.size(),n=s2.size();
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<m||j<n){
            int t=0;
            if(j==n||(i<m && s1[i][0]<s2[j][0])) t=s1[i][0];
            else if(i==m || s2[j][0]<s1[i][0]) t=s2[j][0];
            else t=s1[i][0];

            int v1=0,v2=0;
            if(i<m && s1[i][0]==t){
                v1 = s1[i][1]; i++;
            }else if(i<m) v1 = s1[i][1];
                
            if(j<n && s2[j][0]==t){
                v2 = s2[j][1]; j++;
            }else if(j<n) v2 = s2[j][1];

            ans.push_back({t, v1+v2});
        }

        return ans;
    }
};
