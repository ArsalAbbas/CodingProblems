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
            
        
    }
};