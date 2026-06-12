/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // Node* t=root;
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            for(int i=0;i<x;i++){
                Node* fr = q.front(); q.pop();
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
                if(i!=x-1) fr->next = q.front();
            }
        }
        return root;
    }
};
