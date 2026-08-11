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
    ListNode* h; int n=0;
public:
    Solution(ListNode* head) {
        h = head;
        ListNode* t=h;
        while(t){
            t=t->next; n++;
        }
    }

    int getRandom() {
        ListNode* tt = h;
        int x = rand()%n;
        while(x--){
            tt=tt->next;
        }
        return tt->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
