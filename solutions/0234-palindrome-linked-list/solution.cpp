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
    bool check(vector<int> vec){
        if(vec.size() == 1) return true;
        int i=0, j=vec.size()-1;
        while(i<=j){
            if(vec[i]!=vec[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode*temp = head;
        while(temp != nullptr){
          vec.push_back(temp->val), temp = temp->next;  
        }
        return check(vec);    
    }
};
