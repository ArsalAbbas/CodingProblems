class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    
        
        ListNode *mergedHead=new ListNode(0);
        ListNode *merged=mergedHead;
        
        while(list1!=NULL && list2 !=NULL){
            if(list1->val < list2->val){
                merged->next=list1;
                list1=list1->next;
            }
            else
            {
                merged->next=list2;
                list2=list2->next;
            }
            // else{
            //     merged->next=list1;
            //     merged=merged->next;
            //     merged->next=list2;
            //     list1=list1->next;
            //     list2=list2->next; 
            // }
            merged=merged->next;
        }
        if(list1!=NULL){
            cout<<merged->val;
        merged->next=list1;

        }
        if (list2!=NULL)
            merged->next=list2;
        // merged->next=NULL;
        return mergedHead->next;        
    }
};