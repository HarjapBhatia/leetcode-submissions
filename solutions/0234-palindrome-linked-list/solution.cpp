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
    // bool check(vector<int> vec){
    //     if(vec.size() == 1) return true;
    //     int i=0, j=vec.size()-1;
    //     while(i<=j){
    //         if(vec[i]!=vec[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    bool isPalindrome(ListNode* head) {
        ListNode* f=head, *s=head;
        while(f && f->next){
            f=f->next->next; s=s->next;
        }
        ListNode* prev=s;
        s=s->next;
        prev->next = nullptr;
        while(s){
            ListNode* temp = s->next;
            s->next = prev;
            prev = s;
            s = temp;
        }
        f=head; s=prev;
        while(s){
            if(f->val!=s->val) return false;
            f=f->next; s=s->next;
        }
        return true;

        // vector<int> vec;
        // ListNode*temp = head;
        // while(temp != nullptr){
        //   vec.push_back(temp->val), temp = temp->next;  
        // }
        // return check(vec);    
    }
};
