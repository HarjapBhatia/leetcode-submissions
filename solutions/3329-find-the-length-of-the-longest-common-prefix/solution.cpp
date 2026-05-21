class Node{
public:
    Node* next[10];
    Node(){
        for(int i=0;i<10;i++){
            next[i] = nullptr;
        }
    }
};

class Trie{
public:
    Node *root;
    Trie(){
        root = new Node();
    }

    void insert(int n){
        Node* node = root;
        string s = to_string(n);
        for(char c : s){
            int i = c-'0';
            if(!node->next[i])
                node->next[i] = new Node();
            node = node->next[i];
        }
    }

    int longestPref(int n){
        Node* node = root;
        string s = to_string(n);
        int len=0;
        for(char c : s){
            int i = c-'0';
            if(node->next[i]){
                len++;
                node = node->next[i];
            }else break;
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t; int ans =0;
        for(int x : arr1) t.insert(x);
        for(int x : arr2){
            int l = t.longestPref(x);
            ans = max(ans, l);
        }
        return ans;
    }
};
