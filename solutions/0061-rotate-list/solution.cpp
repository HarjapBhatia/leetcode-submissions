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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int n=1;
        ListNode* t=head;
        while(t->next) {n++; t=t->next;}
        k%=n;
        if(k==0) return head;
        t->next=head;
        int cnt=1;
        ListNode* u=head;
        while(cnt < n-k) {u=u->next; cnt++;} 
        ListNode* nh = u->next;
        u->next=nullptr;
        return nh;
    }
};
