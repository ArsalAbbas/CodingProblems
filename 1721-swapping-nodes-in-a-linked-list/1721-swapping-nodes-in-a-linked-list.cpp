/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 
       3  53 2 32  2 6 632 5 235  5
      ..
       
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left = head;
        ListNode* right = head;
        ListNode* curr = head;
        
        
        while(curr!=NULL){
            if (k>1)
                left = left->next;
            if (k<=0)
                right = right->next;
            curr = curr->next;
            k--;
        }
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
        
        return head;
    }
};