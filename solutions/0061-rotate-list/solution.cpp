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
        ListNode* temp = head;
        int size = 1;
        while(temp->next != nullptr){
            temp = temp->next;
            size++;
        }
        temp->next = head; // making it circularr
        k=k%size;
        if(k==0){
            temp->next=nullptr;
            return head; 
        } 
        int n = size-k;
        ListNode* temp2 = head;
        for(int i=1;i<n;i++) temp2 = temp2->next;
        ListNode* newHead = temp2->next;
        temp2->next = nullptr;
        return newHead;
    }
};
