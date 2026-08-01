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
    ListNode* deleteDuplicates(ListNode* head) {    
        if(!head || !head->next) return head; 
        ListNode* i=head, *j=head;
        while(j){
            if(i->val!=j->val){
                i->next = j; i=i->next;
            }
            j=j->next;
        }
        i->next = j;
        return head;
    }
};
