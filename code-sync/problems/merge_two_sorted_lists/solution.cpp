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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
        if(!list1)
            return list2;
        
        if(!list2)
            return list1;
        
        int i=0,j=0;
        
        ListNode* head=new ListNode(-1),*prev=head;
        if(list1->val<=list2->val){
            head->next=new ListNode(list1->val);
            list1=list1->next;
            i++;
        }
        else{
            head->next=new ListNode(list2->val);
            list2=list2->next;
            j++;
        }
        head=head->next;
        
        while(list1 and list2){
            if(list1 and list1->val<=list2->val){
                head->next=new ListNode(list1->val);
                list1=list1->next;
                head=head->next;
            }
            else if(list2 and list2->val<list1->val){
                head->next=new ListNode(list2->val);
                list2=list2->next;
                head=head->next;
            }
            
        }
        while(list1){
            head->next=new ListNode(list1->val);
                list1=list1->next;
                head=head->next;
        }
        while(list2){
            head->next=new ListNode(list2->val);
                list2=list2->next;
                head=head->next;
        }
        return prev->next;
    }
};