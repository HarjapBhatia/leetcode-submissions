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

 /*
    approach :
    - find the middle node, put the right part in stack (including mid)
    - the left part points to nullptr,
    - pop the stacks and add the node between two nodes
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast=head, *slow=head;
        //calc. first mid / node before mid
        while(fast->next and fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        // create the stack and insert the elem.
        stack<ListNode*>st;
        ListNode* temp = slow->next;
        slow->next = nullptr;
        while(temp) {
            st.push(temp); temp=temp->next;
        }

        // add the nodes from stack
        ListNode* f=head;
        while(!st.empty() and f->next){
            ListNode* s=st.top(); st.pop();
            s->next = f->next;
            f->next = s;
            f = f->next->next;
        }
        while(!st.empty()){
            ListNode* s=st.top(); st.pop();
            s->next = f->next;
            f->next = s;
            f = f->next;
        }
    }
};
