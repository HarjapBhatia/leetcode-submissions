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
    ListNode* mid(ListNode* head){
        ListNode* fas=head, *slo=head;
        while(fas->next && fas->next->next){
            fas=fas->next->next;
            slo=slo->next;
        }
        return slo;
    }

    ListNode* rev(ListNode* head){
        ListNode* prev=nullptr, *cur=head, *nxt=nullptr;
        while(cur){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* fhalf = mid(head);
        ListNode* shalf = rev(fhalf->next);
        fhalf->next = nullptr;
        //spliting ll in two and reversing the second half
        int ans = 0;
        while(shalf){
            // cout << head->val << " " << shalf->val << "\n";
            ans = max(ans, head->val+shalf->val);
            shalf=shalf->next; 
            head=head->next;
        }
        return ans;
    }
};
