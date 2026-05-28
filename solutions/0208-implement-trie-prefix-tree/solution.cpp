class Node{
public:
    bool end;
    Node* nxt[26];
    Node(){
        end = false;
        for(int i=0;i<26;i++) {nxt[i] = nullptr;}
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* t = root;
        for(char x : word){
            if(!t->nxt[x-'a']){
                t->nxt[x-'a'] = new Node();
            }
            t = t->nxt[x-'a'];
        }
        t->end = true;
    }
    
    bool search(string word) {
        Node* t = root;
        for(char c : word){
            if(!t->nxt[c-'a']) return false;
            t = t->nxt[c-'a'];
        }
        return t->end;
    }
    
    bool startsWith(string prefix) {
        Node* t = root;
        for(char c : prefix){
            if(!t->nxt[c-'a']) return false;
            t = t->nxt[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
