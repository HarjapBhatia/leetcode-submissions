class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        map<int,int> idx;
        for(int i=0;i<n;i++) idx[positions[i]] = i;

        stack<pair<int, int>> st;
        for(auto it : idx){
            int i=it.second;
            int h = healths[i]; char d = directions[i];
            bool f=false;

            while(!st.empty() && d =='L' && directions[st.top().first]=='R'){
                if(st.top().second == h){
                    f = true; st.pop(); break;
                }else if(st.top().second > h){
                    f = true; st.top().second--; break;
                }else{
                    st.pop(); h--;
                }
            }

            if(!f) st.push({i,h});
        }
        vector<pair<int,int>> rem;
        while(!st.empty()){
            rem.push_back(st.top()); 
            st.pop();
        }
        sort(rem.begin(),rem.end());
        
        vector<int> res;
        for(auto x : rem) res.push_back(x.second);
        return res;
    }
};
