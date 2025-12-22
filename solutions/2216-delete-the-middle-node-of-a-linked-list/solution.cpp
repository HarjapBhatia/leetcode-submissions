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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = nullptr;
        if(head->next == nullptr) return temp;
        ListNode* mid = head, *end = head;
        while(end != nullptr && end->next != nullptr){
            end = end->next->next;
            mid = mid->next;
        }
        ListNode* prev = head;
        while(prev->next != mid) prev = prev->next;
        prev->next = mid->next;
        return head; 
    }
};
