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
    // ListNode* rev(ListNode* l){
    //     ListNode* prev = nullptr, *cur = l;
    //     while(cur){
    //         ListNode* nxt = cur->next;
    //         cur->next=prev;
    //         prev=cur;
    //         cur=nxt;
    //     }
    //     return prev;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode();
        ListNode* ans = temp;
        int cy=0, tot=0;
        while(l1 || l2 || cy){
            tot=cy;
            if(l1){
                tot += l1->val;
                l1=l1->next;
            }
            if(l2){
                tot += l2->val;
                l2=l2->next;
            }

            temp->next = new ListNode(tot%10);
            cy = tot/10;
            temp = temp->next;
        }
        
        return ans->next;

        // ListNode *t2 = l2;
        // ListNode *t1 = l1;
        // ListNode* ans=nullptr;
        // int cy=0;
        // while(t1 && t2){
        //     int x = cy+t1->val+t2->val;
        //     if(x>9){
        //         if(!ans){
        //             ans = new ListNode(x%10);
        //         }else{
        //             ListNode* t = new ListNode(x%10);
        //             t->next=ans;
        //             ans = t;
        //         }
        //         cy = x/10;
        //     }else{
        //         if(!ans){
        //             ans = new ListNode(x);
        //         }else{
        //             ListNode* t = new ListNode(x);
        //             t->next=ans;
        //             ans = t;
        //         }
        //         cy=0;
        //     }
        //     t1 = t1->next;
        //     t2 = t2->next;
        // }
        
        // while(t1){
        //     int x = cy+t1->val;
        //     if(x>9){
        //         if(!ans){
        //             ans = new ListNode(x%10);
        //         }else{
        //             ListNode* t = new ListNode(x%10);
        //             t->next=ans;
        //             ans = t;
        //         }
        //         cy = x/10;
        //     }else{
        //         if(!ans){
        //             ans = new ListNode(x);
        //         }else{
        //             ListNode* t = new ListNode(x);
        //             t->next=ans;
        //             ans = t;
        //         }
        //         cy=0;
        //     }
        //     t1 = t1->next;
        // }
        // while(t2){
        //     int x = cy+t2->val;
        //     if(x>9){
        //         if(!ans){
        //             ans = new ListNode(x%10);
        //         }else{
        //             ListNode* t = new ListNode(x%10);
        //             t->next=ans;
        //             ans = t;
        //         }
        //         cy = x/10;
        //     }else{
        //         if(!ans){
        //             ans = new ListNode(x);
        //         }else{
        //             ListNode* t = new ListNode(x);
        //             t->next=ans;
        //             ans = t;
        //         }
        //         cy=0;
        //     }
        //     t2 = t2->next;
        // }
        // while(cy>0){
        //     ListNode* t = new ListNode(cy%10);
        //     cy/=10;
        //     t->next=ans;
        //     ans = t;
        // }

        // return rev(ans);
    }
};
