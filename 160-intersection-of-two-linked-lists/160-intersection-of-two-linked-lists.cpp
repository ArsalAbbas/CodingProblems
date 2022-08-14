/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        while(headA!=NULL){
            ListNode* dummy=headB;
            while(dummy!=NULL){
                if(dummy==headA)
                    return dummy;
                dummy=dummy->next;
            }
            headA=headA->next;            
        }
              return NULL;
    }
};