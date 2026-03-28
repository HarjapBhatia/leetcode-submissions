/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int list_cnt(ListNode *l){
        int cnt=0;
        ListNode *t=l;
        while(t->next){cnt++; t = t->next; }
        return cnt;
    }

    ListNode* fn(int x, ListNode* a, ListNode* b){
        ListNode* t = a;
        ListNode* u = b;
        while(x--) {
            t=t->next;
        }
        while(t!=nullptr && u!=nullptr){
            if(t == u) return t;
            t = t->next;
            u = u->next;
        }
        return nullptr;
    } 

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ca = list_cnt(headA); 
        int cb = list_cnt(headB); 
        int dif = abs(ca-cb);
        if(ca > cb){
            return fn(dif, headA, headB);
        }else return fn(dif, headB, headA);
        // return nullptr;
    }
};
