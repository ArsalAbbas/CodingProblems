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
    bool hasCycle(ListNode *head) {
        
//         unordered_set<ListNode*> nodeSet;
//         while(head!=0){
//             if(nodeSet.find(head)!=nodeSet.end())
//                 return true;
//             nodeSet.insert(head);
//             head=head->next;
//         }
//         return false;
        if (head==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next != NULL && fast->next->next != NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                return true;
            
        }
        return false;
        
    }
};