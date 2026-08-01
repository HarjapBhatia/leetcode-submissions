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
    ListNode *detectCycle(ListNode *head) {
        ListNode* f = head, *s = head;
        while(f and f->next){
            f = f->next->next; s=s->next;
            if(f==s) break;
        }
        if(!(f and f->next)) return nullptr;
        while(head!=s){
            head=head->next; s=s->next;
        }
        return head;
    }
};
