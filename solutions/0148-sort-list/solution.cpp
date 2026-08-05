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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* t1 = l1, *t2 = l2;
        ListNode* x = new ListNode(0);
        ListNode* dummy = x;
        while(t1 && t2){
            if(t1->val < t2->val){
                x->next = t1;
                x = x->next;
                t1 = t1->next;
            }else{
                x->next = t2;
                x = x->next;
                t2 = t2->next;
            }
        }
        while(t1){
            x->next = t1;
            x = x->next;
            t1 = t1->next;
        }
        while(t2){
            x->next = t2;
            x = x->next;
            t2 = t2->next;
        }
        return dummy->next;
    }

    ListNode* mergesort(ListNode* st, ListNode* end, int n){
        if(n <= 1 || st == end) return st;
        int mi = n/2;
        ListNode* m = st;
        for (int i=1;i<mi;i++) {
            m = m->next;
        }
        ListNode* sec = m->next;
        m->next = nullptr;
        ListNode* ll = mergesort(st, m, mi);
        ListNode* rr = mergesort(sec, end, n-mi);
        return merge(ll, rr);
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* t = head;
        int cnt=1;
        while(t->next){
            cnt++;
            t=t->next;
        }
        return mergesort(head, t, cnt);
    }
};
