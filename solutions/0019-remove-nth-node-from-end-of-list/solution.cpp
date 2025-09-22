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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }    
        n = cnt-n;
        if(n==0){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp = head;
        n-=1;
        while(n--) temp = temp->next;
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        return head;
    }
};
