class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        stack<int> st;
        while(fast->next!=NULL && fast->next->next!=NULL){
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next!=NULL){
        st.push(slow->val);
        }
        slow=slow->next;
        while(slow!=NULL){
            cout<<slow->val;
            if(slow->val!=st.top())
                return false;
            st.pop();
            slow=slow->next;
        }
        return true;
//         ListNode* fast=head;
//         ListNode* slow=head;
//         ListNode* dummy=new ListNode();
//         dummy->next=head;
//         while(fast->next!=NULL && fast->next->next!=NULL){
//             slow=slow->next;
//             fast=fast->next->next;
//         } 
//         cout<<slow->val;
//         ListNode* midDummy=slow;
//         while(dummy!=NULL){
            
//         }
        
//         return true;
        }
};