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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* th=list1, *tt = list1 , *temp2 = list2;
        while(temp2->next) temp2 = temp2->next;
        int c1=1, c2=1;
        while(th->next && c1 < a){
            th = th->next;
            c1++;
        }
        while(tt->next && c2 <= b){
            tt = tt->next;
            c2++;
        }
        tt = tt->next;
        th->next = list2;
        temp2->next = tt;
        return list1;
    }
};
