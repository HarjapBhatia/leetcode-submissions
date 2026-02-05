/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode*st, ListNode*end){
        ListNode* prv = nullptr;
        while(st != end){
            ListNode* nxt = st->next;
            st->next = prv;
            prv = st;
            st = nxt;
        }
        return prv;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* x = head;
        for(int i=0;i<k;i++){
            if(!x) return head;
            x=x->next;
        }
        ListNode* ans = rev(head,x);
        head->next = reverseKGroup(x,k);
        return ans;
    }
};
