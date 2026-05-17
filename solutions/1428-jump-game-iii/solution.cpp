class Solution {
public:
    bool canReach(vector<int>& arr, int st) {
        int n = arr.size();
        unordered_set<int> s;
        queue<int> q;
        if(arr[st] == 0) return true;
        q.push(st);
        s.insert(st);
        while(!q.empty()){
            int i = q.front(); q.pop();
            int i1 = i + arr[i], i2 = i - arr[i];
            
            if(i1 >= 0 && i1 < n && s.find(i1)==s.end()){
                if(arr[i1] == 0) return true;
                q.push(i1); s.insert(i1);
            }
            if(i2 >= 0 && i2 < n && s.find(i2)==s.end()){
                if(arr[i2] == 0) return true;
                q.push(i2); s.insert(i2);
            }  
        }
        return false;
    }
};
