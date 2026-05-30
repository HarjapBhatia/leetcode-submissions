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
    int pairSum(ListNode* head) {
        int ans = 0;
        vector<int> v;
        ListNode* t = head;
        while(t->next){
            v.push_back(t->val);
            t=t->next;
        }
        v.push_back(t->val);
        // for(int x : v) cout << x << " ";
        int l=0,r=v.size()-1;
        while(l<=r){
            if(l==r) ans = max(ans, v[l]);
            else ans = max(ans, v[l]+v[r]);
            l++; r--;
        }
        return ans;
    }
};
