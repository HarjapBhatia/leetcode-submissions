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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto a : lists){
            while(a){
                pq.push(a->val);
                a=a->next;
            }
        }
        ListNode* ans=nullptr;
        ListNode* t=nullptr;
        while(!pq.empty()){
            int x=pq.top(); pq.pop();
            if(!ans) {
                t = new ListNode(x); 
                ans=t;
            }
            else{
                ListNode* ln = new ListNode(x);
                t->next = ln;
                t=t->next;
            } 
        }

        return ans;

        //approach 1
        // vector<int> vec;
        // for(auto a : lists){
        //     while(a){
        //         vec.push_back(a->val);
        //         a=a->next;
        //     }
        // }
        // sort(vec.begin(), vec.end());
        // if(vec.size()==0) return nullptr;
        // int i=0;
        // ListNode* ans = new ListNode(vec[0]);
        // ListNode* it = ans;
        // for(int i=1;i<vec.size();i++){
        //     ListNode* t = new ListNode(vec[i]);
        //     it->next=t;
        //     it = it->next;
        // }
        // return ans;
    }
};
